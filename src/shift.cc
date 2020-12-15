#pragma once
#include <string>
#include <unordered_map>
#include "registers.cc"

std::unordered_map<uint32_t, std::string> shift_type ({
    {0x0, "LSL"},
    {0x1, "LSR"},
    {0x2, "ASR"},
    {0x3, "ROR"}
});

std::string shift(uint32_t fragment) {
    //fragment = 8 bits
    //shift type is bits 6 and 5
    uint32_t bit4 = (fragment % 2);
    uint32_t bit7 = (fragment >> 3) & 0x1U;

    uint32_t type = (fragment >> 1) & 0x3;
    std::string type_text = shift_type[type];

    std::string shift_text;

    if (bit4 == 0x1U && bit7 == 0x0U) { // register shift
        shift_text = type_text + " " + get_register((fragment >> 4) & 0xF);
    }
    else { // immediate value shift
        uint32_t immediate_value = (fragment >> 3) & 0x1F;
        if (immediate_value == 0x0U) {
            return "";
        }
        shift_text = type_text + " #" + std::to_string(immediate_value);
    }

    // LSL #4
    // ROR R5
    return shift_text;
}



 //Shifting Code Here for Register ********TO DO*********
    std::string shiftinstruction(uint32_t instruction) {
        
        uint32_t I = (instruction >> 25) & 0x1U;      // Immediate Operand 0 = operand 2 is a register, 1 = operand 2 is an immediate value
        uint32_t Operand2 = instruction & 0xFFFU;           // Operand 2
        //For I = 0 (Register) 
        uint32_t Shift =  (instruction >> 4) & 0xFFU;   // Shift applied to Rm
        uint32_t Rm = instruction & 0xFU;               // 2nd Operand register    
        //For I = 1 (Immediate)
        uint32_t Rotate = (instruction >> 8) & 0xFU;    // Shift applied to Imm
        uint32_t Imm = instruction & 0xFFU;             // Unsigned 8 bit Immediate value


        std::string Rximm = ",#" + std::to_string(Imm) + ",";
        std::string Rxreg = ",R" + std::to_string(Rm) + ","; //possibly change to getregister(rm) + ","
        std::string OP2a = (I == 0x1U) ? Rximm : Rxreg;
                return OP2a;

        if (((Shift & 0x6U) == 0x0U) && I == 0) //shift type logical left
        {
           std::string stype = "LSL";
        }
        else if(((Shift & 0x6U) == 0x2U) || I == 1) // shift type logical right (Fill in the left side with 0s)
        {
            std::string stype = "LSR";
        }
        else if(((Shift & 0x6U) == 0x4U) && I == 0) // shift type arithmetic right (Fill in the left side with what is contained in bit 31)
        {
            std::string stype = "ASR";
        }
        else if(((Shift & 0x6U) == 0x6U) && I == 0) // shift type rotate right
        {
            std::string stype = "ROR";
            
        }

        std::string reg = (Shift & 0x1U) ? (" R" + std::to_string((Shift >> 4) & 0xFU)) : " #" + std::to_string((Shift >> 3) & 0x1FU); //possibly change to getregister((Shift >> 4) & 0xFU)) + ","

        uint32_t OP2imm =(2*Rotate); //rotate right by twice rotate field
        
        std::string imm = " #" + std::to_string(OP2imm) ;

        std::string OP2b = (I == 0x1U) ? imm : reg; 
            return OP2b;

        
        // we want to return Rx, SHIFTTYPE, SHIFT AMOUNT
    }