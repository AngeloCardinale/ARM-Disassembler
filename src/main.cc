#include <vector>
#include <string>
#include <iostream>

#include "handlers/handle_data_processing.cc"
#include "handlers/handle_multiply.cc"
#include "handlers/handle_multiply_long.cc"
// #include "handle_.cc"
// #include "handle_.cc"
// #include "handle_.cc"
// #include "handle_.cc"

#include "read_executable.cc"
#include "instruction_types.cc"
#include "utils.cc"

using namespace std;

int main( int argc, char** argv) {
    vector<uint32_t> instructions; 
    instructions = read_executable(argv[1]);

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

    print_to_file(argv[2], output);

    return 0;
}