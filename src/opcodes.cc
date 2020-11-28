#include <unordered_map>
#include <string>

// opcodes as per section 4.5.1
std::unordered_map<unsigned int, std::string> opcodes = {
    {0x0, "AND"},
    {0x1, "EOR"},
    {0x2, "SUB"},
    {0x3, "RSB"},
    {0x4, "ADD"},
    {0x5, "ADC"},
    {0x6, "SBC"},
    {0x7, "RSC"},
    {0x8, "TST"},
    {0x9, "TEQ"},
    {0xA, "CMP"},
    {0xB, "CMN"},
    {0xC, "ORR"},
    {0xD, "MOV"},
    {0xE, "BIC"},
    {0xF, "MVN"},
};