#include<map>
#include<iostream>
#include <vector>
#include <string>
using namespace std;

// // This is a map between ARM Condition Codes (the leading 4 bits of an instruction) and their instruction suffixes
// std::unordered_map<unsigned int, std::string> condition_codes = 
// {
//     {0x0, "EQ"},   //equal
//     {0x1, "NE"},   //not equal
//     {0x2, "CS"},   //unsigned higher or same
//     {0x3, "CC"},   //unsigned lower
//     {0x4, "MI"},   //negative
//     {0x5, "PL"},   //positive or zero
//     {0x6, "VS"},   //overflow
//     {0x7, "VC"},   //no overflow
//     {0x8, "HI"},   //unsigned higher
//     {0x9, "LS"},   //unsigned lower or same"
//     {0xA, "GE"},   //greater or equal
//     {0xB, "LT"},   //less than
//     {0xC, "GT"},   //greater than
//     {0xD, "LE"},   //less than or equal
//     {0xE, "AL"}    //always (in the absence of a suffix, the condition field of most instructions is set to "always")
// };



// enum intstruction_type {
//     data_processing
//     multiply
//     multiply_long
// };

// map<instruction_type, uint32_t> instruction_type_masks ({
//     {data_processing: 0xFACB45},
//     {multiply: 0xAAC54FA},
//     ...
// });

// bool check_bits(uint32_t instruction, uint32_t mask, uint32_t expected) {
//     return (instruction & mask) == expected;
// }


// instruction_type get_instruction_type(uint32_t instruction) {
//     instruction_type output;
//     for (const auto& [type_of_instruction, bitmask_for_instruction] : instruction_type_masks) {
//         if (check_bits(instruction, bitmask_for_instruction)) {
//             output = type_of_instruction;
//         }
//     }

//     return output;  // data_processing, multiply, or multiply_long
// }

// string handle_data_processing(uint32_t instruction) {
//     // check if bit n is a 0
//     conditkon_code = condition_codes[get_condition_code(instruciton)] // get the leading 4 btis
//     .// or we can say if (check_bit_number(instruciton, 6, 1)) {}    if bit number 6 of instruction is a 1 then ....
//     if (instruciton && 0x00100000 == 0x0010000) {
//         // then bits 11 - 0 are register 2
//     }
//     else if () {

//     }
// }

// main() {
// for instruction : instructions:
//     // get the type
//     instruction_type type = get_instruction_type(instruction)
//     vector<string> output; 
//     switch(type) {
//         case intstruction_type::data_processing:
//             output.push_back(handle_data_processing(instruction))
//             break;
//         case intstruction_type::multiply:
//             output.push_back(handle_multiply(instruciton))
//             break;
//         case intstruction_type::multiply_long:
//             output.push_back(handle_multiply_long(intstruction))
//             break;
//     }
// }


std::map<uint32_t, std::string> condition_codes = 
{
    {0x0, "EQ"},   //equal
    {0x1, "NE"},   //not equal
    {0x2, "CS"},   //unsigned higher or same
    {0x3, "CC"},   //unsigned lower
    {0x4, "MI"},   //negative
    {0x5, "PL"},   //positive or zero
    {0x6, "VS"},   //overflow
    {0x7, "VC"},   //no overflow
    {0x8, "HI"},   //unsigned higher
    {0x9, "LS"},   //unsigned lower or same"
    {0xA, "GE"},   //greater or equal
    {0xB, "LT"},   //less than
    {0xC, "GT"},   //greater than
    {0xD, "LE"},   //less than or equal
    {0xE, "AL"}    //always (in the absence of a suffix, the condition field of most instructions is set to "always")
};

string get_condition_code(uint32_t instruction) {
    return condition_codes[(instruction >> 28) & 0xF];
}

vector<uint32_t> read_file(const char* filepath) {
    vector<uint32_t>instructions; 
    return instructions;
}

enum instruction_type {
    data_processing,
    multiply,
    multiply_long
};

instruction_type get_instruction_type(uint32_t instruction) {
    // now we do our if statements for getting the type of instruction
    // CPE390 kids write this function
    return instruction_type::data_processing;
}

string handle_data_processing(uint32_t instruction) {
    // CPE390 kids write this to handle a data_processing instruction
}

string handle_multiply(uint32_t instruction) {
    // CPE390 kids write this to handle a multiply instruction
    string output = "";
    string cond = get_condition_code(instruction);
    uint32_t A = (instruction >> 21) & 0x1;
    uint32_t S = (instruction >> 20) & 0x1;
    uint32_t Rd = (instruction >> 16) & 0xF;
    uint32_t Rn = (instruction >> 12) & 0xF;
    uint32_t Rs = (instruction >> 8) & 0xF;
    uint32_t Rm = instruction & 0xF;
    if(A == 1)
    {
        if(S == 1)
        {
            cout << dec << "MLA" << condition(cond) << "S " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "," << reg(Rn) << "\n";
        }
        else
        {
            cout << dec << "MLA" << condition(cond) << " " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "," << reg(Rn) << "\n";
        }
    }
    else
    {
        if(S == 1)
        {
            cout << dec << "MUL" << condition(cond) << "S " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "\n";
        }
        else
        {
            cout << dec << "MUL" << condition(cond) << " " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "\n";
        }
    }

    outupt = get_output_string(cond, operation, r1, r2);
    return output;
}

string handle_multiply_long(uint32_t instruction) {
    // CPE390 kids write this to handle a multiply_long instruction
}

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
}