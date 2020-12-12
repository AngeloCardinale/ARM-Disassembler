#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"
#include "../op_codes.cc"

std::string handle_data_processing(uint32_t instruction) {


    std::string cond = get_condition_code(instruction);
    std::string opcode = get_op_code(instruction, 21); 
    
    uint32_t I = (instruction >> 25) & 0x1U;      // Immediate Operand 0 = operand 2 is a register, 1 = operand 2 is an immediate value
    uint32_t S = (instruction >> 20) & 0x1U;      // Set Condition Codes 0 = do not alter condition codes, 1 = set condition codes
    uint32_t Rn = (instruction >> 16) & 0xFU;     // 1st operand register
    uint32_t Rd = (instruction >> 12) & 0xFU;     // Destination register
    uint32_t Operand2 = instruction & 0xFFFU;     // 
    
    std::string instruction_text;
    
   
    return instruction_text;
}