#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"
#include "../registers.cc"

std::string handle_branch_and_exchange(uint32_t instruction) {
    /*
        condition                = 31 - 28 condition field
        000100101111111111110001 = 27 - 4  identifier
        Rn                       = 0 - 3 Operand Register

        BX{cond} Rn
    */

    std::string cond = get_condition_code(instruction);

    uint32_t Rn = instruction & 0xFU;

    std::string instruction_text; 

    return instruction_text = "BX" + cond + " " + get_register(Rn);
}