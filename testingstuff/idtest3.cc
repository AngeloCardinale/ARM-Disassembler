#include <iostream>
#include <cstdint>

using namespace std;

bool bitcheck(uint32_t num, uint32_t pos)
{
    return((num >> (pos - 1)) & 1);
}

int id(uint32_t instruction)
{
    int type;
    bool bits[32];
    for(int i = 1; i <= 32; i++)
    {
        bits[i - 1] = bitcheck(instruction, i);
    }

    if() //data processing
    {
        type = 1;
    }
    else if() //mutli
    {
        type = 2;
    }
    else if() //multi long
    {
        type = 3;
    }
    else if() //single data swap
    {
        type = 4;
    }
    else if() //branch and exchange
    {
        type = 5;
    }
    else if() //halfword data transfer register offset
    {
        type = 6;
    }
    else if() //halfword data transfer immediate offset
    {
        type = 7;
    }
    else if(instruction & 0x04000000 == 0x04000000) //single data transfer
    {
        type = 8;
    }
    else if(instruction & 0x08000000 == 0x08000000) //block data transfer
    {
        type = 9;
    }
    else if(instruction & 0x0A000000 == 0x0A000000) //branch
    {
        type = 10;
    }
    else if(instruction & 0x0C000000 == 0x0C000000) //coprocessor data transfer
    {
        type = 11;
    }
    else if(instruction & 0x0E000000 == 0x0E000000) //coprocessor data operation
    {
        type = 12;
    }
    else if(instruction & 0x0E000010 == 0x0E000010) //coprocessor register transfer
    {
        type = 13;
    }
    else if(instruction & 0x0F000000 == 0x0F000000) //software interupt
    {
        type = 14;
    }
    else
    {
        type = 100;
    }
    return type;
}

int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x0200A0E3; //data processing
    int op3 = 0x30237190; //muti
    int op4 = 0x30837190; //mutiply long
    int op5 = 0x310F4090; //Single data swap
    int op6 = 0x3E0F4080; //Coprocessor data operation

    cout << id(op1) << "\n";
    cout << id(op2) << "\n";
    cout << id(op3) << "\n";
    cout << id(op4) << "\n";
    cout << id(op5) << "\n";
    cout << id(op6) << "\n";
}