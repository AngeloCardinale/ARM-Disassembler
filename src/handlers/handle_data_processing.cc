#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_data_processing(uint32_t instruction) {


    std::string cond = get_condition_code(instruction);

    uint32_t I = (instruction >> 25) & 0x1U;            //  
    uint32_t OpCode = (instruction >> 21) & 0xFU;       // 
    uint32_t S = (instruction >> 20) & 0x1U;            // 
    uint32_t Rn = (instruction >> 16) & 0xFU;            // 
    uint32_t Rd = (instruction >> 12) & 0xFU;            // 
    uint32_t Operand2 = instruction & 0xFFFU;             // 
    
    std::string instruction_text;
      
   
    return instruction_text;
}