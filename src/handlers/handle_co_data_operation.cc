#pragma once
#include <string>
#include <stdio.h>
#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_data_operation(uint32_t instruction) {
    /*
        condition   = 31 - 28  condition field
        1110        = 27 - 24  identifier
        CP Opc      = 23 - 20  Coprocessor Operation Code
        CRn         = 19 - 16  Coprocessor Source / Destination Register
        CRd         = 15 - 12  ARM Destination Register
        CP#         = 11 - 8   Coprocessor Number
        CP          = 7 - 5    Coprocessor Information
        0           = 4        identifier
        CRm         = 3 - 0    Coprocessor Operand Register

        p#                  = unique nuber of the required coprocessor
        <expression 1>      = evaluated to a constant from the CP Opc field
        cd, cn, cm          = evaluate to the valid coprocessor register nums, CRD, CRn, CRm respectively
        <expression 2>      = where present is evaluated to a constant and placed in the CP field
        
        CDP{cond}   p#,<expression 1>,cd,cn,cm{,<expression 2>}
        CDP     p1,10,c1,c2,c3,<expression 2>
    */

    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    uint32_t CPOpc = (instruction >> 20) & 0xFU;
    uint32_t CRn = (instruction >> 16) & 0xFU;
    uint32_t CRd = (instruction >> 12) & 0xFU;
    uint32_t CPnum = (instruction >> 8) & 0xFU;
    uint32_t CP = (instruction >> 5) & 0x7U;
    uint32_t CRm = instruction & 0xFU; 

    if (CP != 0) {
        instruction_text = "CDP" + cond + " p" + std::to_string(CPnum) +"," + std::to_string(CPOpc) + ",c" + std::to_string(CRd) + ",c" + std::to_string(CRn) + ",c" + std::to_string(CRm) + "," + std::to_string(CP);
    }
    else {
        instruction_text = "CDP" + cond + " p" + std::to_string(CPnum) +"," + std::to_string(CPOpc) + ",c" + std::to_string(CRd) + ",c" + std::to_string(CRn) + ",c" + std::to_string(CRm);
    }
    
    return instruction_text; // this return might give issues according to my test file make sure to check it
}