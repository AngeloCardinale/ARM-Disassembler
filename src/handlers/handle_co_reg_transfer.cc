#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"
#include "../registers.cc"

std::string handle_co_reg_transfer(uint32_t instruction) {
    /*
        condition   = 31 - 28  condition field
        1110        = 27 - 24  identifier
        CP Opc      = 23 - 21  Coprocessor Operation Code
        L           = 20       Load/Store Bit
        CRn         = 19 - 16  Coprocessor Source / Destination Register
        Rd          = 15 - 12   ARM Destination Register
        CP#         = 11 - 8   Coprocessor Number
        CP          = 7 - 5    Coprocessor Information
        1           = 4        identifier
        CRm         = 3 - 0    Coprocessor Operand Register

        MRC                 = Move from coprocessor to ARM7TDMI-S register (L=1)
        MCR                 = Move from ARM7TDMI-S register to coprocessor (L=0)
        p#                  = unique nuber of the required coprocessor
        <expression 1>      = evaluated to a constant from the CP Opc field
        Rd                  = Expression evaluationg to a valid ARM7TDMI-S register number
        cn and cm           = evaluate to the valid coprocessor register nums,CRn, CRm respectively
        <expression 2>      = where present is evaluated to a constant and placed in the CP field
        
        <MRC|MCR>{cond}   p#,<expression 1>,cd,cn,cm{,<expression 2>}
        
    */
    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    uint32_t CPOpc = (instruction >> 21) & 0xFU;     // Coprocessor Operation mode
    uint32_t L = (instruction >> 20) & 0x1U;         // 0 = Store to memory, 1 = load from memory
    uint32_t CRn = (instruction >> 16) & 0xFU;       // Coprocessor Operand Register
    uint32_t Rd = (instruction >> 12) & 0xFU;       // Coprocessor Destination Register
    uint32_t CPnum = (instruction >> 8) & 0xFU;      // Coprocessor Number
    uint32_t CP = (instruction >> 5) & 0xFU;         // Coprocessor Information
    uint32_t CRm = instruction & 0xFU;               // Coprocessor Operand Register

    if (L == 1) {
        std::string instruction_text = "MRC" + cond + " p" + std::to_string(CPnum) + "," + std::to_string(CPOpc) + "," + get_register(Rd) + ",c" + std::to_string(CRn) + ",c" + std::to_string(CRm) + "," + std::to_string(CP) ;
    }
    else {
        std::string instruction_text = "MCR" + cond + " p" + std::to_string(CPnum) + "," + std::to_string(CPOpc) + "," + get_register(Rd) + ",c" + std::to_string(CRn) + ",c" + std::to_string(CRm) + "," + std::to_string(CP) ;
    }

    return instruction_text;
}