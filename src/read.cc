#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "type_check_funcs.cc"
#include "condition_codes.cc"
#include "opcodes.cc"

int main(int argc, char** argv)
{
    /* 
        ARM instruction sets are little-endian, so the least significant byte is first
    */
    // http://www.cplusplus.com/reference/cstdio/fread/
    FILE* pFile; 
    long lSize;
    char* buffer;
    size_t result;

    pFile = fopen(argv[1], "rb");
    if (pFile == nullptr) {
        fputs("File error", stderr);
        exit(1);
    }

    // get the file size
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    // allocate memory to contain the whole file
    buffer = (char*) malloc(sizeof(char)*lSize);
    if (buffer == nullptr) {
        fputs("Memory error", stderr);
        exit(2);
    }

    // copy the file into the buffer
    result = fread(buffer, 1, lSize, pFile);
    if(result != lSize) {
        fputs("Reading error", stderr);
        exit(3);
    }
    // Whole file is now loaded into the memory buffer

    std::vector<uint32_t> instructions;

    // https://stackoverflow.com/questions/23919953/fetch-32bit-instruction-from-binary-file-in-c
    // instruction |= buffer[3] << 24;      // 0xDD000000
    // instruction |= buffer[2] << 16;      // 0xddCC0000
    // instruction |= buffer[1] << 8;       // 0xddccBB00
    // instruction |= buffer;               // 0xddccbbAA
    for (int i = 0; i < lSize; i+=4) {
        uint32_t instruction = 0u;
        for (int j = 3; j >= 0; j--) {
            instruction |= buffer[i+j] << j*8;
        }
        instructions.push_back(instruction);
    }

    for (int i = 0; i < instructions.size(); i++) {
        uint32_t instruction = instructions.at(i);
        if (isDataProcessing(instruction)) {}
        else if (isMultiply(instruction)) {}
        else if (isMultiplyLong(instruction)) {}
        else if (isSingleDataSwap(instruction)) {}        
        else if (isBranchAndExchange(instruction)) {}
        else if (isHDTRegOffset(instruction)) {}
        else if (isHDTImmOffset(instruction)) {}
        else if (isBlockDataTransfer(instruction)) {}
        else if (isBranch(instruction)) {}
        else if (isCoDataTransfer(instruction)) {}
        else if (isCoDataOperation(instruction)) {}
        else if (isCoRegisterTransfer(instruction)) {}
        else if (isSoftwareInterrupt(instruction)) {}
        else {
            throw;
        }
    }







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
    // for (int i : instructions) {
    //     char cond = (i >> 28) & 0xF; // Bits 31-28, the and is unnecessary if its all 32 bit instructions
    //     char unknown = (i >> 26) & 0x3; // Bits 27-26
    //     char immediate_operand = (i >> 25) % 2; // Bit 25 
    //     char opcode = (i >> 21) & 0xF; // Bits 24-21
    //     char set_cond_codes = (i >> 20) % 2; // Bit 20
    //     char first_operand_register = (i >> 16) & 0xF; // Bits 19-16
    //     char destination_register = (i >> 12) & 0xF; // Bits 15-12
    //     if (immediate_operand) {
    //         char rotate = (i >> 8) & 0xF; // Bits 11-8
    //         char immediate_value = i & 0xFF; // Bits 7-0
    //     } else {
    //         char shift = (i >> 4) & 0xFF; // Bits 11-4
    //         char second_operand_register = i & 0xF; // Bits 3-0
    //     }
    // }

    // terminate
    fclose (pFile);
    free (buffer);
    return 0;
}