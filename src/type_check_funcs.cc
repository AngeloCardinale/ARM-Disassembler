#include <cstdint>

bool isDataProcessing(uint32_t instruction) {
    // 1111 0011 1111 1111 1111 1111 1111 1111
    return (instruction & 0xFFFFFFFF) == 0xF3FFFFFF;
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
