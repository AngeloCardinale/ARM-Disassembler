#include <iostream>

int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x30237190; //muti
    int op3 = 0x30837190; //mutiply long

    int temp = op1;
    temp = temp << 4;

    if((temp & 0x8000000) == 0x8000000)
    {
        temp = temp << 1;
        if((temp & 0x4000000) == 0x4000000)
        {
            temp = temp << 1;
            if((temp & 0x2000000) == 0x2000000)
            {
                temp = temp << 1;
                if((temp & 0x1000000) == 0x1000000)
                {
                    std::cout << "software interupt\n";
                }
                else
                {
                    temp = temp << 20;
                    if((temp & 0x10) == 0x10)
                    {
                        std::cout << "coprocessor register transfer\n";
                    }
                    else
                    {
                        std::cout << "coprocessor data operation\n";
                    }
                }
            }
            else
            {
                std::cout << "coprocessor data transfer\n";
            }
        }
        else
        {
            temp = temp << 1;
            if((temp & 0x2000000) == 0x2000000)
            {
                std::cout << "branch\n";
            }
            else
            {
                std::cout << "block data transfer\n";
            }
        }
    }
    else
    {
        temp << 1;
        if((temp & 0x4000000) == 0x4000000)
        {
            std::cout << "single data transfer\n";
        }
        else
        {
            temp << 2;
            if((temp & 0x12FFF10) == 0x12FFF10)
            {
                std::cout << "branch and exchange\n";
            }
            else
            {
            }
        }
    }
}