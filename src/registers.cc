#pragma once
#include <map>
#include <string>

// go from 🅱️egister addresses to 🅱️egister names

const std::string registers[16] = {
    "R0",
    "R1",
    "R2",
    "R3",
    "R4",
    "R5",
    "R6",
    "R7",
    "R8",
    "R9",
    "R10",
    "R11",
    "R12",
    "SP",
    "LR",
    "PC",
};

const std::string& get_register(uint32_t instruction) {
    return registers[(instruction)];
}