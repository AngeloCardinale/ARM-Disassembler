#include <iostream>
#include <string>
#include <unordered_map>

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

std::unordered_map<uint32_t, instruction_type> bitmasks({
    {0x000000, data_processing},
    {0x000001, multiply},
    {0x000002, multiply_long},
    {0x000003, single_data_swap},
    {0x000004, branch_and_exchange},
    {0x000005, hwdt_reg_offset},
    {0x000006, hwdt_imm_offset},
    {0x000007, single_data_transfer},
    {0x000008, block_data_transfer},
    {0x000009, branch},
    {0x00000A, co_data_transfer},
    {0x00000B, co_data_operation},
    {0x00000C, co_reg_transfer},
    {0x00000D, software_interrupt},
    // {hex_for_mask_to_check_type, instruction_type}
});

std::unordered_map<instruction_type, uint32_t> expected_values({
    {data_processing,       0x000001},
    {multiply,              0x000002},
    {multiply_long,         0x000003},
    {single_data_swap,      0x000004},
    {branch_and_exchange,   0x000005},
    {hwdt_reg_offset,       0x000006},
    {hwdt_imm_offset,       0x000007},
    {single_data_transfer,  0x000008},
    {block_data_transfer,   0x000009},
    {branch,                0x00000A},
    {co_data_transfer,      0x00000B},
    {co_data_operation,     0x00000C},
    {co_reg_transfer,       0x00000D},
    {software_interrupt,    0x00000E},
    // this will be for the expected value for check bits if its different than the mask
});

instruction_type get_instruction_type(uint32_t instruction) {
    for (const auto [mask, type] : bitmasks) {
        uint32_t expected = expected_values[type];
        if (check_bits(instruction, mask, expected) == 1) {
            return type;
        }
    }

    std::cout << "No valid instruction type found\n";
    throw;
}
