#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../registers.cc"
#include "../utils.cc"

std::string handle_hwdt_imm_offset(uint32_t instruction) {
    /*
        cond        = 31 - 28   condition code
        000         = 27 - 25   identifier
        P           = 24        pre/post indexing
        U           = 23        up/down
        1           = 22        identifier
        W           = 21        write-back
        L           = 20        load/store
        Rn          = 19 - 16   base register
        Rd          = 15 - 12   source/destination register
        Offset      = 11 - 8    immediate offset (high nibble)
        1           = 7         identifier
        S H         = 6 - 5     swp, unsigned halfwords, signed byte, signed halfwords
        1           = 4         identifier
        Offset      = 3 - 0     immediate offset (low nibble)

        <LDR|STR>{cond}<H|SH|SB> Rd,<address>

        H           = Transfer halfword quantity
        SB          = Load sign extended byte (only valid for LDR)
        SH          = Load sign extended halfword (only valid for LDR)
        Rd          = is an expression evaluating to a valid register number
        <address>   = an expression which generates an address : this wil be a PC relative, preindexed address
                        pre-indexed addressing specification:
                            [Rn]                    offset of zero
                            [Rn,<#expression>]{!}   offset of <expression> bytes
                            [Rn,{+/-}Rm]{!}        offset of +/- contents of index register
                        post-indexed addressing specification:
                            [Rn],<#expression>      offset of <expression> bytes
                            [Rn],{+/-}Rm            offset of +/- contents of index register
        {!}         = writes back the base register (set the W bit) if ! is present

        STRHR3,[R4,#14]
        LDRNESHR11,[R0]
    */
    
    
    std::string cond = get_condition_code(instruction);
    uint32_t P = (instruction >> 24) & 0x1U;             // 0 = post (add/subtract after transfer), 1 = pre (add/subtract before transfer)
    uint32_t U = (instruction >> 23) & 0x1U;             // 0 = down (subtract offset from base), 1 = up (add offset to base)
    uint32_t W = (instruction >> 21) & 0x1U;             // 0 = No Write-Back, 1 = Write adress into base
    uint32_t L = (instruction >> 20) & 0x1U;             // 0 = Store to memory, 1 = load from memory
    uint32_t Rn = (instruction >> 16) & 0xFU;            // Base register
    uint32_t Rd = (instruction >> 12) & 0xFU;            // Source / Destination Register
    int32_t OffsetHigh = (instruction >> 8) & 0xFU;     // Immediate Offset (High Nibble)
    uint32_t S = (instruction >> 6) & 0x1U;              // If SH = 00 -> SWP instruction, = 01 -> Unsigned Halfwords
    uint32_t H = (instruction >> 5) & 0x1U;              //    If SH = 10 -> Signed byte, 11 -> Signed Halfwords
    int32_t OffsetLow = (instruction) & 0xFU;           // Immediate Offset (Low Nibble)
    int32_t offset = (0x00U | OffsetHigh << 4) | OffsetLow; 

    std::string instruction_text;
    std::string sh_sb_h = get_sb_sh_h(S, H);
    std::string ldr_str = (L == 0x1U) ? "LDR" : "STR";
    std::string exclamation = (W == 0x1U) ? "!" : "";
    std::string address;
    if (P) { // pre indexed
        if (offset == 0x0U) {
            address = "[" + get_register(Rn) + "]";
        } else {
            address = "[" + get_register(Rn) + ',' + "#" + std::to_string(offset) + "]" + exclamation;
        }
    }
    else { // post indexed
        if (offset == 0x0U) {
            address = "[" + get_register(Rn) + "]";
        } else {
            address = "[" + get_register(Rn) + "],#" + std::to_string(offset);  
        }
    }

    instruction_text = ldr_str + cond + sh_sb_h + get_register(Rd) + "," + address;
    return instruction_text;
}  