#include <string>
#include <unordered_map>

// This is a map between ARM Condition Codes (the leading 4 bits of an instruction) and their instruction suffixes
std::unordered_map<uint32_t, std::string> condition_codes({
    {0x0U, "EQ"},   //equal
    {0x1U, "NE"},   //not equal
    {0x2U, "CS"},   //unsigned higher or same
    {0x3U, "CC"},   //unsigned lower
    {0x4U, "MI"},   //negative
    {0x5U, "PL"},   //positive or zero
    {0x6U, "VS"},   //overflow
    {0x7U, "VC"},   //no overflow
    {0x8U, "HI"},   //unsigned higher
    {0x9U, "LS"},   //unsigned lower or same"
    {0xAU, "GE"},   //greater or equal
    {0xBU, "LT"},   //less than
    {0xCU, "GT"},   //greater than
    {0xDU, "LE"},   //less than or equal
    {0xEU, ""}    //always (in the absence of a suffix, the condition field of most instructions is set to "always")
});

std::string get_condition_code(uint32_t instruction) {
    return condition_codes[(instruction >> 28)];
}
