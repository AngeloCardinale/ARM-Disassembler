#pragma once
#include <unordered_map>
#include <string>

//go from 🅱️egister addresses to 🅱️egister names
std::unordered_map<unsigned int, std::string> registers({
    {0x0U, "R0"},
    {0x1U, "R1"},
    {0x2U, "R2"},
    {0x3U, "R3"},
    {0x4U, "R4"},
    {0x5U, "R5"},
    {0x6U, "R6"},
    {0x7U, "R7"},
    {0x8U, "R8"},
    {0x9U, "R9"},
    {0xAU, "R10"},
    {0xBU, "R11"},
    {0xCU, "R12"},
    {0xDU, "SP"},
    {0xEU, "LR"},
    {0xFU, "PC"},
});

std::string get_register(uint32_t instruction) {
    return registers[(instruction)];
}