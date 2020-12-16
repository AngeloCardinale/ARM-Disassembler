#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"
#include "../op_codes.cc"
#include "../registers.cc"
#include "../shift.cc"

std::string handle_data_processing(uint32_t instruction) {
    /*

        condition   = 31 - 28   Condition field
        00          = 27 - 26   Identifier
        I           = 25        Immediate Operand
        OpCode      = 24 - 21   Operation Code:
                                0000 = AND - Rd:= Op1 AND Op2
                                0001 = EOR - Rd:= Op1 EOR Op2
                                0010 = SUB - Rd:= Op1 - Op2
                                0011 = RSB - Rd:= Op2 - Op1
                                0100 = ADD - Rd:= Op1 + Op2
                                0101 = ADC - Rd:= Op1 + Op2 + C
                                0110 = SBC - Rd:= Op1 - Op2 + C - 1
                                0111 = RSC - Rd:= Op2 - Op1 + C - 1
                                1000 = TST - set condition codes on Op1 AND Op2
                                1001 = TEQ - set condition codes on Op1 EOR Op2
                                1010 = CMP - set condition codes on Op1 - Op2
                                1011 = CMN - set condition codes on Op1 + Op2
                                1100 = ORR - Rd:= Op1 OR Op2
                                1101 = MOV - Rd:= Op2
                                1110 = BIC - Rd:= Op1 AND NOT Op2
                                1111 = MVN - Rd:= NOT Op2
        S           = 20        Set Condition Codes
        Rn          = 19 - 16   1st operand register
        Rd          = 15 - 12   Destination Regsiter
        Operand 2   = 11 - 0    Changes based off of I
          If I = 0 then we operand 2 is a register following:
            Shift   = 11 - 4    Shift applied to Rm
            Rm      =  3 - 0    2nd Operand Register
          If I = 1 then operand 2 is an immediate value following:
            Rotate  = 11 - 8    Shift applied to Imm
            Imm     =  7 - 0    Unsigned 8 bit Immediate value
        

        1 MOV,MVN (single operand instructions.):
                <opcode>{cond}{S} Rd,<Op2>
        2 CMP,CMN,TEQ,TST (instructions which do not produce a result.)
                <opcode>{cond} Rn,<Op2>
        3 AND,EOR,SUB,RSB,ADD,ADC,SBC,RSC,ORR,BIC
                <opcode>{cond}{S} Rd,Rn,<Op2>
            where:
                <Op2> is Rm{,<shift>} or,<#expression>
                {S} set condition codes if S present (implied for CMP, CMN, TEQ, TST).
                Rd, Rn and Rm are expressions evaluating to a register number.
                <#expression> if this is used, the assembler will attempt to generate a shifted 
                immediate 8-bit field to match the expression. If this isimpossible, it will give an error.
                <shift> is <shiftname> <register> or <shiftname> #expression, or RRX (rotate right one bit with extend).
                <shiftname>s are: ASL, LSL, LSR, ASR, ROR. (ASL is a synonym for LSL,they assemble to the same code.)
    

    */

    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    std::string opcode = get_op_code(instruction, 21); 
    uint32_t I = (instruction >> 25) & 0x1U;      // Immediate Operand 0 = operand 2 is a register, 1 = operand 2 is an immediate value
    uint32_t S = (instruction >> 20) & 0x1U;      // Set Condition Codes 0 = do not alter condition codes, 1 = set condition codes
    uint32_t Rn = (instruction >> 16) & 0xFU;     // 1st operand register
    uint32_t Rd = (instruction >> 12) & 0xFU;     // Destination register
    uint32_t Operand2 = instruction & 0xFFFU;           // Operand 2
    //For I = 0 (Register) 
    uint32_t Shift =  (instruction >> 4) & 0xFFU;   // Shift applied to Rm
    uint32_t Rm = instruction & 0xFU;               // 2nd Operand register    
    //For I = 1 (Immediate)
    uint32_t Rotate = (instruction >> 8) & 0xFU;    // Shift applied to Imm
    uint32_t Imm = instruction & 0xFFU;             // Unsigned 8 bit Immediate value
    std::string s_flag = (S == 0x1U) ? "S " : " ";
    std::string Rximm = ",#" + std::to_string(Imm); // MOVE COMMA TO SHIFT FUNCTION
    std::string Rxreg =",R" + std::to_string(Rm); //possibly change to getregister(rm) + ","
    //std::string Rximm = (Imm == 0) ?  "" : (",#" + std::to_string(Imm) + ","); // TERNARY CHECK NOT NECESSARY
     //   std::string Rxreg = (Rm == 0) ?  "" :",R" + std::to_string(Rm) + ",";  // TERNARY CHECK NOT NECESSARY
    std::string OP2a = (I == 0x1U) ? Rximm : Rxreg;
   
    // This might give errors if there is nothing to shift by and the instruction should end with Rn not the shift instruction
        
    if (opcode == "MOV" || opcode == "MVN")
    {
        instruction_text = opcode + cond + s_flag + get_register(Rn)  + OP2a + shift(Operand2);
    }
    else if(opcode == "CMP" || opcode == "CMN" || opcode == "TEQ" || opcode == "TST")
    {
        instruction_text = opcode + cond + s_flag + get_register(Rn) + OP2a  + shift(Operand2);
    }
    else
    {
        instruction_text = opcode + cond + s_flag + get_register(Rd)+ "," + get_register(Rn)+ OP2a  + shift(Operand2);
    }

    return instruction_text;
}