#include <vector>
#include <string>
#include <iostream>

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

#include "read_executable.cc"
#include "instruction_types.cc"
#include "utils.cc"

using namespace std;

int main( int argc, char** argv) {

    std::string executable_path = "test.out";
    std::string output_path = "output.txt";

    vector<uint32_t> instructions; 
    instructions = read_executable(executable_path);

    vector<string> output;
    output.reserve(instructions.size());

    for (uint32_t instruction : instructions) {
        instruction_type type = get_instruction_type(instruction);
        
        switch(type) {
            case instruction_type::data_processing:
                output.push_back(handle_data_processing(instruction));
                break;
            case instruction_type::multiply:
                output.push_back(handle_multiply(instruction));
                break;
            case instruction_type::multiply_long:
                output.push_back(handle_multiply_long(instruction));
                break;
            case instruction_type::single_data_swap:
                output.push_back(handle_single_data_swap(instruction));
                break;
            case instruction_type::branch_and_exchange:
                output.push_back(handle_branch_and_exchange(instruction));
                break;
            case instruction_type::hwdt_reg_offset:
                output.push_back(handle_hwdt_reg_offset(instruction));
                break;
            case instruction_type::hwdt_imm_offset:
                output.push_back(handle_hwdt_imm_offset(instruction));
                break;   
            case instruction_type::single_data_transfer:
                output.push_back(handle_single_data_transfer(instruction));
                break;
            case instruction_type::block_data_transfer:
                output.push_back(handle_block_data_transfer(instruction));
                break;
            case instruction_type::branch:
                output.push_back(handle_branch(instruction));
                break;
            case instruction_type::co_data_transfer:
                output.push_back(handle_co_data_transfer(instruction));
                break;
            case instruction_type::co_data_operation:
                output.push_back(handle_co_data_operation(instruction));
                break;
            case instruction_type::co_reg_transfer:
                output.push_back(handle_co_reg_transfer(instruction));
                break;
            case instruction_type::software_interrupt:
                output.push_back(handle_software_interrupt(instruction));
                break;
        }
    }

    print_to_file(output_path, output);

    return 0;
}