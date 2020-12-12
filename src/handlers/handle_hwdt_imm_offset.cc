#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"

std::string handle_hwdt_imm_offset(uint32_t instruction) {
    std::string cond = get_condition_code(instruction);
    std::string operation = "";
    std::string operand1 = "";
    std::string operand2 = "";    

    // INSERT BINARY STUFF HERE
    uint32_t cond = instruction >> 28;                  // Condition Field
    uint32_t P = (instruction >> 24) & 0x1;             // 0 = post (add/subtract after transfer), 1 = pre (add/subtract before transfer)
    uint32_t U = (instruction >> 23) & 0x1;             // 0 = down (subtract offset from base), 1 = up (add offset to base)
    uint32_t W = (instruction >> 21) & 0x1;             // 0 = No Write-Back, 1 = Write adress into base
    uint32_t L = (instruction >> 20) & 0x1;             // 0 = Store to memory, 1 = load from memory
    uint32_t Rn = (instruction >> 16) & 0xF;            // Base register
    uint32_t Rd = (instruction >> 12) & 0xF;            // Source / Destination Register
    uint32_t Offsethigh = (instruction >> 8) & 0xF;     // Immediate Offset (High Nibble)
    uint32_t S = (instruction >> 6) & 0x1;              // If SH = 00 -> SWP instruction, = 01 -> Unsigned Halfwords
    uint32_t H = (instruction >> 5) & 0x1;              //    If SH = 10 -> Signed byte, 11 -> Signed Halfwords
    uint32_t OffsetLow = (instruction) & 0xF;           // Immediate Offset (Low Nibble)
    
    return create_instruction_text(cond, operation, operand1, operand2);
}