#ifndef READ_EXECUTABLE
#define READ_EXECUTABLE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>
#include <string>
#include <iomanip>
#include <bitset>

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
        instruction |= (buffer[i+3] << 24) & 0xFF000000;
        instruction |= (buffer[i+2] << 16) & 0x00FF0000;
        instruction |= (buffer[i+1] << 8) & 0x0000FF00;
        instruction |= (buffer[i]) & 0x000000FF;
        // if ((i + j) == 975) {
        //     std::cout << "975: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 976) {
        //     std::cout << "976: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 977) {
        //     std::cout << "977: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 978) {
        //     std::cout << "978: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        
        // if ((i + j) == 979) {
        //     std::cout << "979: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 980) {
        //     std::cout << "980: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 981) {
        //     std::cout << "981: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        // if ((i + j) == 982) {
        //     std::cout << "982: \n"; 
        //     std::cout << "BYTE: " << std::bitset<8>(buffer[i+j]).to_string() << '\n';
        //     std::cout << "Instruction" << std::bitset<32>(instruction).to_string() << '\n';
        // }
        instructions.push_back(instruction);
    }

    std::cout << "number of instructions is " << instructions.size() << std::endl;
    
    std::ofstream f2("byte_text.txt");
    for (int i =0; i < lSize ; i++) {
        f2 << std::bitset<8>(buffer[i]).to_string() << '\n';
    }
    std::ofstream f("hex_stuff.txt");
    for (std::uint32_t instruction : instructions) {
        f << std::bitset<32>(instruction).to_string() << '\n';
    }
    return instructions;
}

#endif