#pragma once
#include <iostream>
#include <string>
#include <map>
#include <bitset>

#include "handlers/handle_data_processing.cc"
#include "handlers/handle_multiply.cc"
#include "handlers/handle_multiply_long.cc"
#include "handlers/handle_single_data_swap.cc"
#include "handlers/handle_branch_and_exchange.cc"
#include "handlers/handle_hwdt_reg_offset.cc"
#include "handlers/handle_hwdt_imm_offset.cc"
#include "handlers/handle_single_data_transfer.cc"
#include "handlers/handle_block_data_transfer.cc"
#include "handlers/handle_branch.cc" 
#include "handlers/handle_co_data_transfer.cc"
#include "handlers/handle_co_data_operation.cc"
#include "handlers/handle_co_reg_transfer.cc"
#include "handlers/handle_software_interrupt.cc"
#include "handlers/handle_undefined.cc"

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
    undefined,
};

typedef std::string(*handler_function)(uint32_t);

// make the intsruciton_type just funciton pointers to the handlers
std::map<uint32_t, handler_function> bitmasks ({
    {0x0F000000U, handle_software_interrupt},
    {0x0E000010U, handle_co_reg_transfer},
    {0x0E000000U, handle_co_data_operation},
    {0x0C000000U, handle_co_data_transfer},
    {0x0A000000U, handle_branch},
    {0x08000000U, handle_block_data_transfer},
    {0x04000000U, handle_single_data_transfer},
    {0x00400090U, handle_hwdt_imm_offset},
    {0x00000090U, handle_hwdt_reg_offset},
    {0x012FFF10U, handle_branch_and_exchange},
    {0x01000090U, handle_single_data_swap},
    {0x00800090U, handle_multiply_long},
    {0x00000090U, handle_multiply},
    {0x06000010U, handle_undefined},
    {0x00000000U, handle_data_processing},
    // {hex_for_mask_to_check_type, instruction_type}
});

handler_function get_handler_function(uint32_t instruction) {
    int counter = 0;
    std::map<uint32_t, handler_function>::reverse_iterator it;
    for (it = bitmasks.rbegin(); it != bitmasks.rend(); it++) {
        if (check_bits(instruction, it->first, it->first) == 1) {
            if (it->second == instruction_type::multiply || it->second == instruction_type::hwdt_reg_offset) {
                if(((instruction >> 5) & 0x1U == 0x0U) && ((instruction >> 6) & 0x1U == 0x0U) && ((instruction >> 23) & 0x1U == 0x0U) && ((instruction >> 24) & 0x1U == 0x0U)) {
                    return handle_multiply;
                }
                else {
                    return handle_hwdt_reg_offset;
                }
            }
            return it->second;
        }
    }
    std::cout << "No valid instruction type found\n";
    throw;
}