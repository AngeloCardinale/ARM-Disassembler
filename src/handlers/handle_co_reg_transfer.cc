#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_co_reg_transfer(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    // INSERT BINARY STUFF HERE
    uint32_t cond = instruction >> 28;              // Condition Field
    uint32_t CPOpc = (instruction >> 21) & 0xF;     // Coprocessor Operation mode
    uint32_t L = (instruction >> 20) & 0x1;         // 0 = Store to memory, 1 = load from memory
    uint32_t CRn = (instruction >> 16) & 0xF;       // Coprocessor Operand Register
    uint32_t CRd = (instruction >> 12) & 0xF;       // Coprocessor Destination Register
    uint32_t CPnum = (instruction >> 8) & 0xF;        // Coprocessor Number
    uint32_t CP = (instruction >> 5) & 0xF;         // Coprocessor Information
    uint32_t CRm = instruction & 0xF;               // Coprocessor Operand Register

    If (L == 1)
    {
        std::string instruction_text = "MRC" + cond + " p" + to_string(CPnum) + "," + to_string(CPOpc) + ",R" + to_string(CRd) + ",c" + to_string(CRn) + ",c" + to_string(CRm) + "," to_string(CP) ;
    }
    else if (L == 0)
    {
        std::string instruction_text = "MCR" + cond + " p" + to_string(CPnum) + "," + to_string(CPOpc) + ",R" + to_string(CRd) + ",c" + to_string(CRn) + ",c" + to_string(CRm) + "," to_string(CP) ;
    }

    return create_instruction_text(cond, operation, operand1, operand2);
}