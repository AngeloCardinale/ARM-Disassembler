#pragma once
#include <iostream>
#include <string>
#include <map>
#include <bitset>
#include "utils.cc"

enum instruction_type {
    data_processing,
    multiply,
    multiply_long,
    single_data_swap,
    branch_and_exchange,
    hwdt_reg_offset, // halfword data transfer: register offset
    hwdt_imm_offset, // halfword data transfer: immediate offset
    single_data_transfer,
    block_data_transfer,
    branch,
    co_data_transfer,  // coprocessor data transfer
    co_data_operation, // coprocessor data operation
    co_reg_transfer,   // coprocessor register transfer
    software_interrupt,
};

std::map<uint32_t, instruction_type> bitmasks ({

    {0x0F000000U, instruction_type::software_interrupt},
    {0x0E000010U, instruction_type::co_reg_transfer},
    {0x0E000000U, instruction_type::co_data_operation},
    {0x0C000000U, instruction_type::co_data_transfer},
    {0x0A000000U, instruction_type::branch},
    {0x08000000U, instruction_type::block_data_transfer},
    {0x04000000U, instruction_type::single_data_transfer},
    {0x00400090U, instruction_type::hwdt_imm_offset},
    {0x00000090U, instruction_type::hwdt_reg_offset},
    {0x012FFF10U, instruction_type::branch_and_exchange},
    {0x01000090U, instruction_type::single_data_swap},
    {0x00800090U, instruction_type::multiply_long},
    {0x00000090U, instruction_type::multiply},
    {0x00000000U, instruction_type::data_processing},

    // {hex_for_mask_to_check_type, instruction_type}
});

instruction_type get_instruction_type(uint32_t instruction) {
    int counter = 0;
    std::map<uint32_t, instruction_type>::reverse_iterator it;
    for (it = bitmasks.rbegin(); it != bitmasks.rend(); it++) {
        if (check_bits(instruction, it->first, it->first) == 1) {
            if (it->second == instruction_type::multiply || it->second == instruction_type::hwdt_reg_offset) {
                if(((instruction >> 5) & 0x1U == 0x0U) && ((instruction >> 6) & 0x1U == 0x0U) && ((instruction >> 23) & 0x1U == 0x0U) && ((instruction >> 24) & 0x1U == 0x0U)) {
                    return multiply;
                }
                else {
                    return hwdt_reg_offset;
                }
            }
            return it->second;
        }
    }

    std::cout << "No valid instruction type found\n";
    throw;
}
