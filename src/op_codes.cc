#pragma once
#include <string>

// op codes for data processng instructions
const std::string op_codes[16] = {
    "AND",
    "EOR",
    "SUB",
    "RSB",
    "ADD",
    "ADC",
    "SBC",
    "RSC",
    "TST",
    "TEQ",
    "CMP",
    "CMN",
    "ORR",
    "MOV",
    "BIC",
    "MVN",
};

const std::string& get_op_code(uint32_t instruction, uint32_t right_shift) {
    return op_codes[(instruction >> right_shift) & 0xF];
}