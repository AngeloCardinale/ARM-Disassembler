#include <cstdint>
/*
        XNOR    == 
    1 1     1
    1 0     0
    0 1     0
    0 0     1
*/
bool isDataProcessing(uint32_t instruction) {
    // xxxx 00xx xxxx xxxx xxxx xxxx xxxx xxxx  Data processing instruction
    // 0011 0000 1110 0001 0010 0000 0000 0101 // "real" data processing instruction

    // 0000 0000 0000 0000 0000 0000 0000 0000
    // 1100 1111 0001 1110 1101 1111 1111 1111
    // passes = good

    // xxxx 0000 00xx xxxx xxxx xxxx 1001 xxxx Multiply Instruction
    // passes = bad
    return (instruction & 0xF3FFFFFF) == 0xF3FFFFFF;
}

bool isMultiply(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isMultiplyLong(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isSingleDataSwap(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isBranchAndExchange(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isHDTRegOffset(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isHDTImmOffset(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isBlockDataTransfer(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isBranch(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isCoDataTransfer(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isCoDataOperation(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isCoRegisterTransfer(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}

bool isSoftwareInterrupt(uint32_t instruction) {
    return (instruction & 0xFFFFFFFF) == ;
}
