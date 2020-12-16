#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_software_interrupt(uint32_t instruction) {
   
   /*

        Cond            = 31 - 28  Condition field
        1111            = 27 - 24  Identifier
        Comment Field   = 23 - 0   Used to communicate information to the supervisor code

        <expression>   = is evaluated and placed in the comment field which is ignored by ARM7TDMI-S
        SWI{cond} <expression>
   */
   
    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    uint32_t Comment = instruction & 0xFFFFFFU;            // Comment Field

    instruction_text = "SWI" + cond + ' ' + std::to_string(Comment);
   
    return instruction_text;
}