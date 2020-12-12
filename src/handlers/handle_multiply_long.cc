#include <string>

#include "../condition_codes.cc"
#include "../registers.cc"
#include "../utils.cc"

std::string handle_multiply_long(uint32_t instruction) {
    /*
        cond    = 31 - 28  condition code
        00001   = 27 - 23  identifier
        U       = 22       Unsigned
        A       = 21       Accumulate bit
        S       = 20       Set Condition Code
        RdHi    = 19 - 16  Destition Register high
        RdLo    = 15 - 12  Destition Register low
        Rs      = 11 - 8   Operand Register
        1001    = 7 - 4    identifier
        Rm      = 3 - 0    Operand Register

        UMULL{cond}{S} RdLo,RdHi,Rm,Rs
        UMLAL{cond}{S} RdLo,RdHi,Rm,Rs
        SMULL{cond}{S} RdLo,RdHi,Rm,Rs
        SMLAL{cond}{S} RdLo,RdHi,Rm,Rs
    */
    std::string cond = get_condition_code(instruction);

    uint32_t U = (instruction >> 22) & 0x1U;
    uint32_t A = (instruction >> 21) & 0x1U;
    uint32_t S = (instruction >> 20) & 0x1U;
    uint32_t RdHi = (instruction >> 16) & 0xFU;
    uint32_t RdLo = (instruction >> 12) & 0xFU;
    uint32_t Rs = (instruction >> 8) & 0xFU;
    uint32_t Rm = instruction & 0xFU;

    std::string instruction_text;
    std::string s_flag = (S == 0x1U) ? "S" : "";
    std::string u_flag = (U == 0x1U) ? "S" : "U";
    if (A) {
        instruction_text = u_flag + "MLAL" + cond + s_flag + ' ' + get_register(RdLo) + ',' + get_register(RdHi) + ',' + get_register(Rm) + ',' + get_register(Rs);
    }
    else {
        instruction_text = u_flag + "MULL" + cond + s_flag + ' ' + get_register(RdLo) + ',' + get_register(RdHi) + ',' + get_register(Rm) + ',' + get_register(Rs);
    }
    
    return instruction_text;
}