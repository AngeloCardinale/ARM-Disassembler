/*
    Project Flow:
        bitmap.cc
            class Bitmap {}
                defines a bitmap of an arbitrary size, where the bits are stored as int8_t
            class ARMBitmap : public Bitmap {}
                defined a bitmap for use with the ARM Assembler Instructionset - 32 bits, little-endian
        
        instruction_types.cc
            enum arm_instruction_types 
                defines all of the instruction set formats possible for ARM (there are 14)
            
        masks.cc
            std::unordered_map<arm_instruction_types, ARMBitmap> arm_bitmasks
                defines a dictionary mapping the arm instruction types to their appropriate bitmaps

            struct labeled_bitmask {
                arm_instruction_type label;
                ARMBitmask mask;
            }
                defines a struct used to group an instruction type to the approptiate bitmask - this is so that we can
                group this data with a templated class like std::list or std::vector

        read_executable.cc
            std::vector<uint32_t> instructions read_executable(const char *filepath) {}
                returns a vector of instructions read in from a file
        
        instruction_handlers.cc
            defines a set of functions to handle each kind of instruciton format
            ex:
                std::string handle_data_processing(uint32_t instruction) {}

        main.cc
            int main(int argc, char** argv) {
                std::vector<uint32_t> instructions = read_executable(argv[1]);
                std::vector<std::string> output;
                output.reserve(instructions.size());

                // for each instruction
                for (int i = 0; i < instructions.size(); i++) { // O(n)
                    
                    // define the current instruction
                    uint32_t instruction = instructions.at(i);

                    // define a list of possible instruction types
                    std::list<labeled_bitmask> possible_types   //using a list for O(1) add/remove time
                    
                    // populate the possible types list
                    for (auto const& [k, v] : masks) { // O(1)
                        possible_types.push_back({k, v});
                    }
                    // define an iterator for that list
                    std::list<labeled_bitmask>::iterator it;

                    // iterate through the current instruction bit by bit to check type
                    for (int i = 0, x = 31; i < 31; i++, x--) { // O(1)
                        
                        // get the current bit of the input instruction
                        uint8_t current bit = (instruction >> i) % 2;

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

                        if (possible_masks.size() != 1):
                            throw; // that means that the instruction was bad
                        
                        arm_instruction_type type = possible_masks.at(0).label;
                        switch(type) {
                            case arm_instruction_type.data_processing:
                                output.push_back(handle_data_processing(instruction));
                                break;
                            ...
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
*/