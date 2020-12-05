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
            std::vector<uint32_t> read_executable(const char *filepath) {}
                returns a vector of instructions read in from a file
        
        instruction_handlers.cc
            defines a set of functions to handle each kind of instruciton format
            ex:
                std::string handle_data_processing(uint32_t instruction) {}

        main.cc
            run through the instructions and parse them
            location of main switch statement
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

                ...

                default:
                    output.push_back("parsing error");
                    break; 
            }

            for (auto& i : output) {
                std::cout << i << '\n';
            }
*/