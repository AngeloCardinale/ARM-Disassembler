#include <cstdint>
#include <string>

using namespace std;

string reg(uint32_t reg)
{
    if(reg == 0xD)
    {
        return "SP";
    }
    else if(reg == 0xE)
    {
        return "LR";
    }
    else if(reg == 0xF)
    {
        return "PC";
    }
    else
    {
        return "R" + to_string(reg);
    } 
}
string condition(uint32_t concode)
{
    if(concode == 0x0)
    {
        return "EQ";
    }
    else if(concode == 0x1)
    {
        return "NE";
    }
    else if(concode == 0x2)
    {
        return "CS";
    }
    else if(concode == 0x3)
    {
        return "CC";
    }
    else if(concode == 0x4)
    {
        return "MI";
    }
    else if(concode == 0x5)
    {
        return "PL";
    }
    else if(concode == 0x6)
    {
        return "VS";
    }
    else if(concode == 0x7)
    {
        return "VC";
    }
    else if(concode == 0x8)
    {
        return "HI";
    }
    else if(concode == 0x9)
    {
        return "LS";
    }
    else if(concode == 0xA)
    {
        return "GE";
    }
    else if(concode == 0xB)
    {
        return "LT";
    }
    else if(concode == 0xC)
    {
        return "GT";
    }
    else if(concode == 0xD)
    {
        return "LE";
    }
    else
    {
        return "";
    }
}