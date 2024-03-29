#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_branch(uint32_t instruction) {
    /*
        condition = 31 - 28 condition field
        101       = 27 - 25 identifier
        L         = 24      link bit
        offset    = 24 - 0  offset  

        B{L}{cond} <expression>
    */
   
    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    uint32_t L = (instruction >> 24) & 0x1U;
    uint32_t offset = instruction & 0xFFFFFFU;
    
    std::string L_flag = (L == 0x1U) ? "L" : "";
    
    return instruction_text = "B" + L_flag + cond + " " + std::to_string(offset);
}