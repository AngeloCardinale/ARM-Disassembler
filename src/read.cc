#include <iostream>
#include <fstream>
#include <iomanip>

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
        char cond = i >> 28; // should be the leading 4 bits
        // no idea about bits 27 and 26
        char immediateOperand = (i >> 15) % 2; // should give us if the immediate operand is 0 or 1
        char opCode = (i << 7) >> 28; // left shift 31-24 to get opCode at the front, then right shift 21+7 to bring it to the back
        char setCondCodes = (i >> 20) % 2; // get the 20th bit
        char firstOperandRegister = (i << 12) >> 28;
        char destinationRegister = (i << 16) >> 28;
        if (immediateOperand) {
            char rotate = ;
            char immediateValue = ;
        } else {
            char shift = ;
            char secondOperandRegister = ;
        }
    }


    return 0;
}