#ifndef INSTRUCTION_HANDLERS
#define INSTRUCTION_HANDLERS

#include <iostream>
#include <string>

std::string handle_data_processing(uint32_t instruction) {
    return "data processing!";
}

std::string handle_multiply(uint32_t instruction) {
    return "multiply!";
}

std::string handle_multiply_long(uint32_t instruction) {
    return "multiply long!";
}

std::string handle_single_data_swap(uint32_t instruction) {
    return "single data swap!";
}

#endif