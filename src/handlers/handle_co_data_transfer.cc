#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_data_transfer(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    uint32_t cond = instruction >> 28;                  // Condition Field
    uint32_t P = (instruction >> 24) & 0x1;             // 0 = post (add/subtract after transfer), 1 = pre (add/subtract before transfer)
    uint32_t U = (instruction >> 23) & 0x1;             // 0 = down (subtract offset from base), 1 = up (add offset to base)
    uint32_t N = (instruction >> 22) & 0x1;             // Transfer length
    uint32_t W = (instruction >> 21) & 0x1;             // 0 = No Write-Back, 1 = Write adress into base
    uint32_t L = (instruction >> 20) & 0x1;             // 0 = Store to memory, 1 = load from memory
    uint32_t Rn = (instruction >> 16) & 0xF;            // Base register
    uint32_t CRd = (instruction >> 12) & 0xF;           // Coprocessor source/destination register
    uint32_t CPnum = (instruction >> 8) & 0xF;            // Coprocessor Number
    uint32_t Offset = instruction & 0xFF;               // Unsigned 8 bit immediate offset
    
    
    return create_instruction_text(cond, operation, operand1, operand2);
}