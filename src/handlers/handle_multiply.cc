#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../registers.cc"
#include "../utils.cc"

std::string handle_multiply(uint32_t instruction) {
    
    /*
        cond        = 31 - 28   condition code
        000000      = 27 - 22   identifier
        A           = 21        Accumulate
        S           = 20        Set Condition Code
        Rd          = 19 - 16   Destination Register
        Rn          = 15 - 12   Operand Register
        Rs          = 11 - 8    Operand Register
        1001        = 7 - 4     Operand Register
        Rm          = 3 - 0     Operand Register

        MUL{cond}{S} Rd,Rm,Rs
        MLA{cond}{S} Rd,Rm,Rs,Rn 
    */
    
    std::string cond = get_condition_code(instruction);
    std::string instruction_text;
    
    uint32_t A = (instruction >> 21) & 0x1U;
    uint32_t S = (instruction >> 20) & 0x1U;
    uint32_t rd = (instruction >> 16) & 0xFU;
    uint32_t rn = (instruction >> 12) & 0xFU;
    uint32_t rs = (instruction >> 8) & 0xFU;
    uint32_t rm = (instruction) & 0xFU;
    std::string s_flag = (S == 0x1U) ? "S" : "";
    
    if (A) { // MLA
        instruction_text = "MLA" + cond + s_flag + ' ' + get_register(rd) + ',' + get_register(rm) + ',' + get_register(rs) + ',' + get_register(rn);
    }
    else { // MUL
        instruction_text = "MUL" + cond + s_flag + ' ' + get_register(rd) + ',' + get_register(rm) + ',' + get_register(rs);
    }

    return instruction_text;
}