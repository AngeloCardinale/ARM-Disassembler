// g++ -std=c++17 -g src/main.cc 
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <bits/stdc++.h>

#include "read_executable.cc"
#include "masks.cc"
#include "instruction_handlers.cc"
#include "instruction_types.cc"

using namespace std;
int main(int argc, char** argv) {
    std::vector<uint32_t> instructions = read_executable("test.out");
    std::vector<std::string> output;
    output.reserve(instructions.size());

    // for each instruction
    for (int i = 0; i < instructions.size(); i++) { // O(n)
        
        // define the current instruction
        uint32_t instruction = instructions.at(i);

        // define a copy of the arm bitmatsks dict
        std::unordered_map<arm_instruction_types, ARMBitmap> bitmaps = arm_bitmasks;

        // define a new list that contains 
        // iterate through the list of possible instruction masks
        for (int j = 0, x = 31; j < 31; j++, x--) {
            // 1 or 0, current instruction bit
            signed char current_bit = (instruction >> j) % 2; 

            // for each bitmask
            for (const auto& [k, v] : arm_bitmasks) {
                // if you're out of options or cant find the key then break / continue
                if (bitmaps.size() == 0) {
                    std::cout << "no possible types\n";
                    throw; // that means that the instruction was bad                    
                }
                if (bitmaps.find(k) == bitmaps.end()) {
                    continue;
                }

                // current mask bit we are comparing to -1, 0, 1
                signed char mask_bit = (bitmaps[k])[x];  

                // if mask_bit is -1, skip
                if (mask_bit == -1) {
                    continue;
                } 
                // if mask_bit is not -1
                else {
                    // if mask_bit does not match the current bit
                    if (mask_bit != current_bit) {
                        // then remove that instruction type from the list of possible instruction types
                        bitmaps.erase(k);
                    } 
                    // if mask_bit matches the current bit then continue on
                }
            }    
        }

        // if the instruction does not match exactly one instruction type, then error
        if (bitmaps.size() != 1) {
            std::cout << "no possible types\n";
            throw; // that means that the instruction was bad
        }
        
        // the correct instruction type is the first (and now only) member of the bitmaps dictionary
        arm_instruction_types type = (*bitmaps.begin()).first; // the key
        switch(type) {
            case arm_instruction_types::data_processing:
                output.push_back(handle_data_processing(instruction));
                break;

            case arm_instruction_types::multiply:
                output.push_back(handle_multiply(instruction));
                break;

            case arm_instruction_types::multiply_long:
                output.push_back(handle_multiply_long(instruction));
                break;

            case arm_instruction_types::single_data_swap:
                output.push_back(handle_single_data_swap(instruction));
                break;

            default:
                output.push_back("parsing error");
                break; 
        }
    }
    
    for (auto& i : output) {
        std::cout << i << '\n';
    }

    return 0;
}