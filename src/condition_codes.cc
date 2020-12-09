#include <string>
#include <unordered_map>

// This is a map between ARM Condition Codes (the leading 4 bits of an instruction) and their instruction suffixes
std::unordered_map<unsigned int, std::string> condition_codes({
    {0x0, "EQ"},   //equal
    {0x1, "NE"},   //not equal
    {0x2, "CS"},   //unsigned higher or same
    {0x3, "CC"},   //unsigned lower
    {0x4, "MI"},   //negative
    {0x5, "PL"},   //positive or zero
    {0x6, "VS"},   //overflow
    {0x7, "VC"},   //no overflow
    {0x8, "HI"},   //unsigned higher
    {0x9, "LS"},   //unsigned lower or same"
    {0xA, "GE"},   //greater or equal
    {0xB, "LT"},   //less than
    {0xC, "GT"},   //greater than
    {0xD, "LE"},   //less than or equal
    {0xE, ""}    //always (in the absence of a suffix, the condition field of most instructions is set to "always")
});

std::string get_condition_code(uint32_t instruction) {
    return condition_codes[(instruction >> 28)];
}
