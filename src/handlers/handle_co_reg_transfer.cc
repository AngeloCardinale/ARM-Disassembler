#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_reg_transfer(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    // INSERT BINARY STUFF HERE
    uint32_t cond = instruction >> 28;              // Condition Field
    uint32_t CPOpc = (instruction >> 21) & 0xF;     // Coprocessor Operation mode
    uint32_t L = (instruction >> 20) & 0x1;         // 0 = Store to memory, 1 = load from memory
    uint32_t CRn = (instruction >> 16) & 0xF;       // Coprocessor Operand Register
    uint32_t CRd = (instruction >> 12) & 0xF;       // Coprocessor Destination Register
    uint32_t CPnum = (instruction >> 8) & 0xF;        // Coprocessor Number
    uint32_t CP = (instruction >> 5) & 0xF;         // Coprocessor Information
    uint32_t CRm = instruction & 0xF;               // Coprocessor Operand Register
    
    return create_instruction_text(cond, operation, operand1, operand2);
}