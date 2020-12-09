#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_multiply_long(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    // INSERT BINARY STUFF HERE
    
    return create_instruction_text(cond, operation, operand1, operand2);
}