/*
⚖️ 👷 ✔️
done             name
⚖️             software_interrupt  The comment  / output might be wrong check this
⚖️             co_reg_transfer
⚖️             co_data_operation
👷             co_data_transfer
⚖️             branch
👷             block_data_transfer
👷             single_data_transfer
⚖️             hwdt_imm_offset
⚖️             hwdt_reg_offset
⚖️             branch_and_exchange
⚖️             single_data_swap
⚖️             multiply_long
⚖️             multiply
👷             data_processing










handle_data_processing.cc
hanlde ... .cc
    these contain all of the handling functions

condition_codes.cc
    condition_codes map

instruciton_type.cc
    contains instruction type enum 
    contains instructino id map
    
utils.cc 
    contains any convenience functions we have

main.cc
    int main( int argc, char** argv) {
        vector<uint32_t> instructions; 
        instructions = read_file(argv[1]);

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
            }
        }

        output output to file
    }

*/