#pragma once
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
    std::string condition_code, std::string operation, std::string operand1="", std::string operand2="", std::string operand3="", std::string operand4="", std::string operand5="") {
        std::string space = " ";
        return condition_code + space + operation + space + operand1 + space + operand2 + space + operand3 + space + operand4 + space + operand5;
}

std::string get_sb_sh_h(uint32_t s, uint32_t h) {
    std::string sh_sb_h;
    if (s) {
        std::string sh_sb_h = (h == 0x1U) ? "SH" : "SB";

    }
    else {
        std::string sh_sb_h = (h == 0x1U) ? "H" : "";
    }

    return sh_sb_h;
} 