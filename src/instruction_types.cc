#include <iostream>
#include <string>
#include <map>

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

std::map<uint32_t, instruction_type> bitmasks({
    {0x00000DU, software_interrupt},
    {0x00000CU, co_reg_transfer},
    {0x00000BU, co_data_operation},
    {0x00000AU, co_data_transfer},
    {0x000009U, branch},
    {0x000008U, block_data_transfer},
    {0x000007U, single_data_transfer},
    {0x000006U, hwdt_imm_offset},
    {0x000004U, branch_and_exchange},
    {0x000003U, single_data_swap},
    {0x000002U, multiply_long},
    {0x000001U, multiply},
    {0x000000U, data_processing},

    // {hex_for_mask_to_check_type, instruction_type}
});

instruction_type get_instruction_type(uint32_t instruction) {
    for (const auto& [mask, type] : bitmasks) {
        if (check_bits(instruction, mask, mask) == 1) {
            return type;
        }
    }

    std::cout << "No valid instruction type found\n";
    throw;
}
