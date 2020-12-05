#include <iostream>
#include <vector>
#include <list>
#include <string>

#include "read_executable.cc"
#include "masks.cc"
#include "instruction_handlers.cc"
#include "instruction_types.cc"

using namespace std;
int main(int argc, char** argv) {
    vector<uint32_t> instructions = read_executable(argv[1]);
    vector<string> output;
    output.reserve(instructions.size());

    // for each instruction
    for (int i = 0; i < instructions.size(); i++) { // O(n)
        
        // define the current instruction
        uint32_t instruction = instructions.at(i);

        // define a list of possible instruction types
        std::list<labeled_bitmask> possible_types;   //using a list for O(1) add/remove time
        
        // populate the possible types list
        for (auto const& [k, v] : masks) { // O(1)
            possible_types.push_back({k, v});
        }
        // define an iterator for that list
        std::list<labeled_bitmask>::iterator it;

        // iterate through the current instruction bit by bit to check type
        for (int i = 0, x = 31; i < 31; i++, x--) { // O(1)
            
            // get the current bit of the input instruction
            uint8_t current_bit = (instruction >> i) % 2;

            // iterate through the list of possible instruction masks
            while(it != possible_masks.end()) { // O(1)

                // save the mask bit
                uint8_t mask_bit = (*it).mask[i];

                // if it is a skip bit then skip
                if (mask_bit == -1) {
                    ++it;
                
                //if it is not a skip bit
                } else {

                    // if the mask bit and the current bit match
                    if (mask_bit == current_bit) {
                        // awesome, this passed the current bit filter
                        ++it;
                    
                    // if they do not match, erase that from the list of possible instructions
                    } else {
                        possible_types.erase(it++);
                    }
                }
            }

            if (possible_masks.size() != 1)
                throw; // that means that the instruction was bad
            
            arm_instruction_type type = possible_masks.at(0).label;
            switch(type) {
                case arm_instruction_type.data_processing:
                    output.push_back(handle_data_processing(instruction));
                    break;
                /* ... */
                default:
                    output.push_back("parsing error");
                    break; 
            }
        }
    }
    
    for (auto& i : output) {
        std::cout << i << '\n';
    }
}