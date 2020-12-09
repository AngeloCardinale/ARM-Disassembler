//print functions for bitwise implementation
#include "miscfuncts.cc"

using namespace std;

void branchandex(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    uint32_t Rn = instruction & 0xF;
    cout << dec << "BX" << condition(cond) << " " << reg(Rn) << "\n";
}

void multiply(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    uint32_t A = (instruction >> 21) & 0x1;
    uint32_t S = (instruction >> 20) & 0x1;
    uint32_t Rd = (instruction >> 16) & 0xF;
    uint32_t Rn = (instruction >> 12) & 0xF;
    uint32_t Rs = (instruction >> 8) & 0xF;
    uint32_t Rm = instruction & 0xF;
    if(A == 1)
    {
        if(S == 1)
        {
            cout << dec << "MLA" << condition(cond) << "S " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "," << reg(Rn) << "\n";
        }
        else
        {
            cout << dec << "MLA" << condition(cond) << " " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "," << reg(Rn) << "\n";
        }
    }
    else
    {
        if(S == 1)
        {
            cout << dec << "MUL" << condition(cond) << "S " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "\n";
        }
        else
        {
            cout << dec << "MUL" << condition(cond) << " " << reg(Rd) << "," << reg(Rm) << "," << reg(Rs) << "\n";
        }
    }
}

void multiplylong(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    uint32_t U = (instruction >> 22) & 0x1;
    uint32_t A = (instruction >> 21) & 0x1;
    uint32_t S = (instruction >> 20) & 0x1;
    uint32_t RdHi = (instruction >> 16) & 0xF;
    uint32_t RdLo = (instruction >> 12) & 0xF;
    uint32_t Rs = (instruction >> 8) & 0xF;
    uint32_t Rm = instruction & 0xF;
    if(U == 1)
    {
        if(A == 1)
        {
            if(S == 1)
            {
                cout << dec << "SMLAL" << condition(cond) << "S " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
            else
            {
                cout << dec << "SMLAL" << condition(cond) << " " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
        }
        else
        {
            if(S == 1)
            {
                cout << dec << "SMULL" << condition(cond) << "S " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
            else
            {
                cout << dec << "SMULL" << condition(cond) << " " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
        }
    }
    else
    {
        if(A == 1)
        {
            if(S == 1)
            {
                cout << dec << "UMLAL" << condition(cond) << "S " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
            else
            {
                cout << dec << "UMLAL" << condition(cond) << " " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
        }
        else
        {
            if(S == 1)
            {
                cout << dec << "UMULL" << condition(cond) << "S " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
            else
            {
                cout << dec << "UMULL" << condition(cond) << " " << reg(RdLo) << "," << reg(RdHi) << "," << reg(Rm) << "," << reg(Rs) << "\n";
            }
        }
    }
}

void singledataswap(uint32_t instruction)
{
    uint32_t cond = instruction >> 28;
    uint32_t B = (instruction >> 22) & 0x1;
    uint32_t Rn = (instruction >> 16) & 0x1;
    uint32_t Rd = (instruction >> 12) & 0x1;
    uint32_t Rm = instruction & 0xF;
    if(B == 1)
    {
        cout << dec << "SWP" << condition(cond) << "B " << reg(Rd) << "," << reg(Rm) << ",[" << reg(Rn) << "]\n";
    }
    else
    {
        cout << dec << "SWP" << condition(cond) << " " << reg(Rd) << "," << reg(Rm) << ",[" << reg(Rn) << "]\n";
    }
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
    uint32_t cond = instruction >> 28;
    uint32_t L = (instruction >> 24) & 0x1;
    uint32_t offset = instruction & 0xFFFFFF;
    if(L == 1)
    {
        cout << dec << "BL" << condition(cond) << " " << offset;
    }
    else
    {
        cout << dec << "B" << condition(cond) << " " << offset;
    }
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
    uint32_t expression = instruction & 0xFFFFFF;
    cout << dec << "SWI" << condition(cond) << " " << expression << "\n";
}

void dataprocessing(uint32_t instruction)
{
    cout << "data processing\n";
}