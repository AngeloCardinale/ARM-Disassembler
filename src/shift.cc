#pragma once
#include <string>

 //Shifting Code Here for Register ********TO DO*********
    std::string shift(uint32_t instruction) {
        
        uint32_t I = (instruction >> 25) & 0x1U;      // Immediate Operand 0 = operand 2 is a register, 1 = operand 2 is an immediate value
        uint32_t Operand2 = instruction & 0xFFFU;           // Operand 2
        //For I = 0 (Register) 
        uint32_t Shift =  (instruction >> 4) & 0xFFU;   // Shift applied to Rm
        uint32_t Rm = instruction & 0xFU;               // 2nd Operand register    
        //For I = 1 (Immediate)
        uint32_t Rotate = (instruction >> 8) & 0xFU;    // Shift applied to Imm
        uint32_t Imm = instruction & 0xFFU;             // Unsigned 8 bit Immediate value

        if ((Shift & 0x6U) == 0x0U) //shift type logical left
        {
           std::string type = "LSL";
           return type;
           // uint32_t OP2reg = (Shift & 0x1U) ? Rm << ((Shift >> 4) & 0xFU) : Rm << ((Shift >> 3) & 0x1FU) ; 
            //uint32_t OP2reg = Rm << ((shift >> 3) & 0x1FU);
            //uint32_t OP2reg = Rm << ((shift >> 4) & 0x1FU);
        }
        else if((Shift & 0x6U) == 0x2U) // shift type logical right (Fill in the left side with 0s)
        {
            std::string type = "LSR";
           return type;
           // uint32_t OP2reg = (Shift & 0x1U) ? Rm >> ((Shift >> 4) & 0xFU) : Rm >> ((Shift >> 3) & 0x1FU) ;
            //uint32_t OP2reg = Rm >> ((shift >> 3) & 0x1FU); //****CHECK HOW TO MAKE LOGICAL VS ARITHMETIC****
        }
        else if((Shift & 0x6U) == 0x4U) // shift type arithmetic right (Fill in the left side with what is contained in bit 31)
        {
            std::string type = "ASR";
           return type;
            //uint32_t OP2reg = (Shift & 0x1U) ? Rm >> ((Shift >> 4) & 0xFU) : Rm >> ((Shift >> 3) & 0x1FU) ;
            //uint32_t OP2reg = Rm >> ((shift >> 3) & 0x1FU); //****CHECK HOW TO MAKE ARITHMETIC VS LOGICAL****
        }
        else if((Shift & 0x6U) == 0x6U) // shift type rotate right
        {
            std::string type = "ROR";
           return type;
            //uint32_t OP2reg = (Shift & 0x1U) ? ((Rm >> ((Shift >> 4) & 0xFU)) | (Rm << 32 - ((Shift >> 4) & 0xFU))) : ((Rm >> ((Shift >> 3) & 0x1FU)) | (Rm << 32 - ((Shift >> 3) & 0x1FU))) ;
            //uint32_t OP2reg = ((Rm >> ((shift >> 3) & 0x1FU)) | (Rm << 32 - ((shift >> 3) & 0x1FU))) ; //****ROTATE TO FILL (TAKE FROM THE RIGHT SIDE AND MOVE TO LEFT)****
        }

        uint32_t OP2imm =Imm >> (2*Rotate); //rotate right by twice rotate field
        
        std::string OP2 = (I == 0x1U) ? std::to_string(OP2imm) : std::to_string(OP2reg);
            return OP2;
    }