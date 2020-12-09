#include <vector>
#include <string>
#include <fstream>

bool check_bits(uint32_t input, uint32_t bitmask, uint32_t expected) {
    return (input & bitmask) == expected;
}

void print_to_file(std::string filepath, std::vector<std::string>  &instructions) {
    std::ofstream f(filepath);
    for (std::string instruction : instructions) {
        f << instruction << '\n';
    }
}

std::string create_instruction_text(
    std::string condition_code, std::string operation, std::string operand1="", std::string operand2="") {
        std::string space = " ";
        return condition_code + space + operation + operand1 + space + operand2;
}