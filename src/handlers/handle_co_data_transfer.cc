#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_data_transfer(uint32_t instruction) {
    /*
        condition   = 31 - 28   condition field
        110         = 27 - 25   identifier
        P           = 24        Pre/Post indexing bit:  0 = post (add/subtract after transfer), 1 = pre (add/subtract before transfer)
        U           = 23        Up/Down bit:  0 = down (subtract offset from base), 1 = up (add offset to base)
        N           = 22        Transfer Length
        W           = 21        Write-back bit:  0 = No Write-Back, 1 = Write adress into base
        L           = 20        Load/Store bit:  0 = Store to memory, 1 = load from memory
        Rn          = 19 - 16   Base Register
        CRd         = 15 - 12   Coprocessor source/destination register     
        CP# (CPnum) = 11 - 8    Coprocessor number
        Offset      =  7 - 0    Unsigned 8 bit immediate offset

        LDC         = Load fromm memory to coprocessor
        STC         = Store from coprocessor to memory
        {L}         = when present perform long transfer (N=1), otherwise perform short transfer (N=0) 
        p#          = unique nuber of the required coprocessor
        cd          = is an expression evaluating to a valid coprocessor register number that is placed in the CRd field
        <Address>   = can be: 1 An expression which generates an address: <expression>
                                The assembler will attempt to generate an instruction using the PC as
                                a base and a corrected immediate offset to address the location given
                                by evaluating the expression. This will be a PC relative, pre-indexed
                                address. If the address is out of range, an error will be generated.
                                2 A pre-indexed addressing specification:
                                    [Rn] offset of zero
                                    [Rn,<#expression>]{!} offset of <expression> bytes
                                3 A post-indexed addressing specification:
                                    [Rn],<#expression> offset of <expression> bytes
                                    {!} write back the base register (set the W bit) if! is present
                                    Rn is an expression evaluating to a valid ARM7TDMI-S register number.
                            NOTE: If Rn is R15, the assembler will subtract 8 from the offset value to allow for pipelining.
        <LDC|STC>{cond} {L}  p#,cd,<Address>
        
    */

    std::string cond = get_condition_code(instruction);

    uint32_t P = (instruction >> 24) & 0x1U;             // 0 = post (add/subtract after transfer), 1 = pre (add/subtract before transfer)
    uint32_t U = (instruction >> 23) & 0x1U;             // 0 = down (subtract offset from base), 1 = up (add offset to base)
    uint32_t N = (instruction >> 22) & 0x1U;             // Transfer length
    uint32_t W = (instruction >> 21) & 0x1U;             // 0 = No Write-Back, 1 = Write adress into base
    uint32_t L = (instruction >> 20) & 0x1U;             // 0 = Store to memory, 1 = load from memory
    uint32_t Rn = (instruction >> 16) & 0xFU;            // Base register
    uint32_t CRd = (instruction >> 12) & 0xFU;           // Coprocessor source/destination register
    uint32_t CPnum = (instruction >> 8) & 0xFU;            // Coprocessor Number
    uint32_t Offset = instruction & 0xFFU;               // Unsigned 8 bit immediate offset

    std::string instruction_text;
    std::string L_flag = (L == 0x1U) ? "L" : "";

    if(L) {
        instruction_text = "LDC" + cond + L_flag ' p' + std::to_string(CPnum) + ',c' + std::to_string(CRd);
    }
    else {
        instruction_text = "STC" + cond + L_flag ' p' + std::to_string(CPnum) + ',c' + std::to_string(CRd);
    }
    retrun instruction_text;
}