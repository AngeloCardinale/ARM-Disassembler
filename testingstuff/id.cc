#include <iostream>
#include <cstdint>

using namespace std;

bool bitcheck(uint32_t num, uint32_t pos)
{
    return((num >> (pos - 1)) & 1);
}

int id(uint32_t instruction)
{
    uint32_t type;
    bool bits[32];
    for(int i = 1; i <= 32; i++)
    {
        bits[i - 1] = bitcheck(instruction, i);
    }
    if((bits[27] == false && bits[26] == false) && (bits[7] == false || bits[4] == false)) //data processing
    {
        type = 1; //data processing = 1
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == false && bits[23] == false && bits[22] == false 
    && bits[7] == true && bits[6] == false && bits[5] == false && bits[4] == true) //multi
    {
        type = 2; //multi = 2
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == false && bits[23] == true && bits[7] == true 
    && bits[6] == false && bits[5] == false && bits[4] == true) //mutli long
    {
        type = 3;
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == true && bits[23] == false && bits[21] == false 
    && bits[20] == false && bits[11] == false && bits[10] == false && bits[9] == false && bits[8] == false && bits[7] == true 
    && bits[6] == false && bits[5] == false && bits[4] == true) //single data swap
    {
        type = 4;
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == true && bits[23] == false && bits[22] == false 
    && bits[21] == true && bits[20] == false && bits[19] == true && bits[18] == true && bits[17] == true && bits[16] == true 
    && bits[14] == true && bits[13] == true && bits[12] == true && bits[11] == true && bits[10] == true && bits[9] == true 
    && bits[8] == true && bits[7] == false && bits[6] == false && bits[5] == false && bits[4] == true) //branch and exchange
    {
        type = 5;
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[22] == false && bits[11] == false && bits[10] == false 
    && bits[9] == false && bits[8] == false && bits[7] == true && bits[4] == true) //Half data transfer reg offset
    {
        type = 6; //Half data transfer reg offset = 6
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[22] == true && bits[7] == true && bits[4] == true) //Half data transfer immediate
    {
        type = 7; //Half data transfer immediate = 7
    }
    else if(bits[27] == false && bits[26] == true) //single word transfer
    {
        type = 8; //single word transfer = 8
    }
    else if(bits[27] == true && bits[26] == false && bits[25] == false) //block data transfer
    {
        type = 9; //block data transfer = 9
    }
    else if(bits[27] == true && bits[26] == false && bits[25] == true) //branch
    {
        type = 10; //branch = 10
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == false) //coprocessor data transfer
    {
        type = 11; //coprocessor data transfer = 11
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == false && bits[4] == false) //coprocessor data operation
    {
        type = 12; //coprocessor data operation = 12
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == false && bits[4] == true) //coprocessor register transfer
    {
        type = 13; //coprocessor register transfer = 13
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == true) //software interupt
    {
        type = 14; //software interupt = 14
    }
    else //bad instruction
    {
        type = 100; //bad boi
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