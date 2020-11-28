#include <iostream>
#include <fstream>
#include <iomanip>
#include "condition_codes.cc"
#include "opcodes.cc"

int main(int argc, char* argv[])
{
    std::ifstream exe(argv[1], std::ios::in|std::ios::binary|std::ios::ate);
    std::streampos size = exe.tellg();
    char* binary = new char[size];
    exe.seekg(0, std::ios::beg);
    exe.read(binary, size);
    exe.close();

    for(int i = 0; i < 32; i++) {
        std::cout << std::setfill('0') << std::setw(2) << std::right << std::hex << int(binary[i]) << " ";
    }
    std::cout << std::endl;

    /*
    CHECK SECTION 4.5
    Bits 31-28 = condition codes
    Bits 27, 26 = Nothing?
    Bit 25 = Immediate Operand (
        if 0, operand 2 is a register and:
            Bits 11-4  = Shift, the shift applied to Rm, 
            Bits 3 - 0 = Rm, second operand register)
        if 1, operand 2 is an immediate value and:
            Bits 11-8 = Rotate, shift applied to Rm
            Bits 7-0 = Imm, Unsigned 8 bit immediate value
    Bits 24 - 21 = OpCode
    Bit 20 = Set Condition Codes (0 = do not alter condition codes, 1 = set cond code)
    Bits 19-16 = Rn first operand register
    Bits 15 - 12 = Rd Destination Register

    */
    // Assuming we have every instruction code 
    for (int i : instruction) {
        char cond = (i >> 28) & 0xF; // Bits 31-28, the and is unnecessary if its all 32 bit instructions
        char unknown = (i >> 26) & 0x3; // Bits 27-26
        char immediate_operand = (i >> 25) % 2; // Bit 25 
        char opcode = (i >> 21) & 0xF; // Bits 24-21
        char set_cond_codes = (i >> 20) % 2; // Bit 20
        char first_operand_register = (i >> 16) & 0xF; // Bits 19-16
        char destination_register = (i >> 12) & 0xF; // Bits 15-12
        if (immediate_operand) {
            char rotate = (i >> 8) & 0xF; // Bits 11-8
            char immediate_value = i & 0xFF; // Bits 7-0
        } else {
            char shift = (i >> 4) & 0xFF; // Bits 11-4
            char second_operand_register = i & 0xF; // Bits 3-0
        }
    }


    return 0;
}