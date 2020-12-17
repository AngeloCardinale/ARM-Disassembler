#include <vector>
#include <string>
#include <iostream>



#include "read_executable.cc"
#include "instruction_types.cc"
#include "utils.cc"

using namespace std;

int main( int argc, char** argv) {

    std::string executable_path = argv[1];
    std::string output_path = argv[2];

    vector<uint32_t> instructions;
    instructions = read_executable(executable_path);

    vector<string> output;
    output.reserve(instructions.size());

    for (uint32_t instruction : instructions) {
        handler_function handle = get_handler_function(instruction);
        output.push_back(handle(instruction));
    }

    print_to_file(output_path, output);

    return 0;
}