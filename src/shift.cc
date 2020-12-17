#pragma once
#include <string>
#include <unordered_map>
#include "registers.cc"


const std::string shift_type[4] = {
    "LSL",
    "LSR",
    "ASR",
    "ROR"
};

std::string shift(uint32_t fragment) {
    uint32_t bit4 = (fragment % 2);
    uint32_t bit7 = (fragment >> 3) & 0x1U;
    uint32_t type = (fragment >> 1) & 0x3;
    std::string type_text = shift_type[type];
    std::string shift_text;

    if (bit4 == 0x1U && bit7 == 0x0U) { // register shift
        shift_text = "," + type_text + " " + get_register((fragment >> 4) & 0xF);
    }
    else { // immediate value shift
        uint32_t immediate_value = (fragment >> 3) & 0x1F;
        if (immediate_value == 0x0U) {
            return "";
        }
        shift_text = "," + type_text + " #" + std::to_string(immediate_value);
    }

    return shift_text;
}