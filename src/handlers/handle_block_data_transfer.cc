#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_block_data_transfer(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);

    // INSERT BINARY STUFF HERE
    
    return create_instruction_text(cond, operation, operand1, operand2);
}