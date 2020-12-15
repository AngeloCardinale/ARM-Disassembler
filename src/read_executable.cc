#ifndef READ_EXECUTABLE
#define READ_EXECUTABLE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>
#include <string>
#include <iomanip>

std::vector<uint32_t> read_executable(std::string fpath) {
    /* 
        ARM instruction sets are little-endian, so the least significant byte is first
    */
    // http://www.cplusplus.com/reference/cstdio/fread/
    FILE* pFile; 
    long lSize;
    char* buffer;
    size_t result;
    const char* filepath = fpath.c_str();
    
    pFile = fopen(filepath, "rb");
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
    std::cout << "number of instructions is " << instructions.size() << std::endl;
    
    std::ofstream f("hex_stuff.txt");
    for (std::uint32_t instruction : instructions) {
        f << std::hex << std::setw(8) << std::setfill('0') << instruction << '\n';
    }
    return instructions;
}

#endif