#pragma once
#include <unordered_map>
#include <string>

std::unordered_map<unsigned int, std::string> op_codes({
    {0x0U, "AND"},
    {0x1U, "EOR"},
    {0x2U, "SUB"},
    {0x3U, "RSB"},
    {0x4U, "ADD"},
    {0x5U, "ADC"},
    {0x6U, "SBC"},
    {0x7U, "RSC"},
    {0x8U, "TST"},
    {0x9U, "TEQ"},
    {0xAU, "CMP"},
    {0xBU, "CMN"},
    {0xCU, "ORR"},
    {0xDU, "MOV"},
    {0xEU, "BIC"},
    {0xFU, "MVN"},
});

std::string get_op_code(uint32_t instruction, uint32_t right_shift) {
    return op_codes[(instruction >> right_shift) & 0xF];
}