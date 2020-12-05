#include <iostream>
#include <cstdint>

using namespace std;

bool bitcheck(uint32_t num, uint32_t pos)
{
    return((num >> (pos - 1)) & 1);
}
int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x30237190; //muti
    int op3 = 0x30837190; //mutiply long
    int op4 = 0x310F4090; //Single data swap
    int op5 = 0x3E0F4080; //Coprocessor data operation

    int temp = op1;
    bool bits[32];

    for(int i = 1; i <= 32; i++)
    {
        bits[i - 1] = bitcheck(temp, i);
    }
}