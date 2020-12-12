#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_data_operation(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    // INSERT BINARY STUFF HERE
    uint32_t cond = instruction >> 28;              // Condition Field
    uint32_t CPOpc = (instruction >> 20) & 0xF;     // Coprocessor Operation Code
    uint32_t CRn = (instruction >> 16) & 0xF;       // Coprocessor Source / Destination Register
    uint32_t CRd = (instruction >> 12) & 0xF;       // ARM Destination Register
    uint32_t CPnum = (instruction >> 8) & 0xF;        // Coprocessor Number
    uint32_t CP = (instruction >> 5) & 0xF;         // Coprocessor Information
    uint32_t CRm = instruction & 0xF;               // Coprocessor Operand Register

    if(CP != 0)
    {
    std::string instruction_text = "CDP" + cond + " p" + to_string(CPnum) +"," + to_string(CPOpc) + ",c" + to_string(CRd) + ",c" + to_string(CRn) + ",c" + to_string(CRm) + "," + to_string(CP);
    }
    else
    {
    std::string instruction_text = "CDP" + cond + " p" + to_string(CPnum) +"," + to_string(CPOpc) + ",c" + to_string(CRd) + ",c" + to_string(CRn) + ",c" + to_string(CRm);
    }
    
    return instruction_text; // this return might give issues according to my test file make sure to check it
}