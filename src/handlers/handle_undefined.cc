#pragma once
#include <string>
#include <bitset>

std::string handle_undefined(uint32_t instruction) {

    return "undefined: " + std::bitset<32>(instruction).to_string();
}