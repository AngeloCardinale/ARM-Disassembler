//print functions for bitwise implementation
#include "miscfuncts.cc"

using namespace std;

void branchandex(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    uint32_t Rn = instruction & 0x0000000F;
    cout << dec << "BX" << condition(cond) << " " << reg(Rn) << "\n";
}

void dataprocessing(uint32_t instruction)
{
    cout << "data processing\n";
}

void multiply(uint32_t instruction)
{
    cout << "multiply\n";
}

void multiplylong(uint32_t instruction)
{
    cout << "multiply long\n";
}

void singledataswap(uint32_t instruction)
{
    cout << "single data swap\n";
}

void halfdatatransreg(uint32_t instruction)
{
    cout << "half word data transfer register offset\n";
}

void halfdatatransimm(uint32_t instruction)
{
    cout << "half word data transfer immediate offset\n";
}

void singledatatrans(uint32_t instruction)
{
    cout << "single data transfer\n";
}

void blockdatatrans(uint32_t instruction)
{
    cout << "block data transfer\n";
}

void branch(uint32_t instruction)
{
    cout << "branch\n";
}

void coprodatatrans(uint32_t instruction)
{
    cout << "coprocessor data transfer\n";
}

void coprodataop(uint32_t instruction)
{
    cout << "coprocessor data operation\n";
}

void coproregtrans(uint32_t instruction)
{
    cout << "coprocessor register transfer\n";
}

void softwareinterrupt(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    cout << dec << "SWI" << condition(cond) << "\n"; //inc for now
}