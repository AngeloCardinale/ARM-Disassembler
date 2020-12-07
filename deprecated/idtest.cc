#include <iostream>

int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x30237190; //muti
    int op3 = 0x30837190; //mutiply long

    int temp = op3;
    temp = temp << 4;                                                   //Bit shift past first 4 unnecessary bits

    if((temp & 0x8000000) == 0x8000000)                                 //Check if First Bit is a 1
    {
        temp = temp << 1;                                               
        if((temp & 0x4000000) == 0x4000000)                             //Check if Second Bit is a 1
        {
            temp = temp << 1;
            if((temp & 0x2000000) == 0x2000000)                         //Check if Third Bit is a 1
            {
                temp = temp << 1;
                if((temp & 0x1000000) == 0x1000000)                     //Check if Fourth Bit is a 1
                {
                    std::cout << "software interupt\n";                 //Instruction Used is Software Interupt
                }
                else                                                    //Fourth Bit is a 0
                {
                    temp = temp << 20;
                    if((temp & 0x10) == 0x10)                           //Check if 27th bit is a 1
                    {
                        std::cout << "coprocessor register transfer\n"; //Instruction used is coprocessor register transfer
                    }
                    else                                                //27th bit is a 0
                    {
                        std::cout << "coprocessor data operation\n";    //Instruction used is coprocessor data Operation
                    }
                }
            }
            else                                                        //3rd bit is a 0 
            {
                std::cout << "coprocessor data transfer\n";             //Instruction used is coprocessor data transfer
            }
        }
        else                                                            //2nd bit is a 0
        {
            temp = temp << 1;
            if((temp & 0x2000000) == 0x2000000)                         // Check if 3rd bit is a 1
            {
                std::cout << "branch\n";                                //Instruction used is branch
            }
            else                                                        //3rd bit is a 0
            {
                std::cout << "block data transfer\n";                   //Instruction used is a block data transfer
            }
        }
    }
    else                                                                //first bit is 0
    {
        temp << 1;
        if((temp & 0x4000000) == 0x4000000)                             //Check if 2nd bit is a 1
        {
            std::cout << "single data transfer\n";                      //Instruction used is single data transfer
        }
        else                                                            //2nd bit is a 0
        {   
            temp << 2;
            if((temp & 0x12FFF10) == 0x12FFF10)                         //Check if we have 000100101111111111110001
            {
                std::cout << "branch and exchange\n";                   //Instruction used is branch and exchange
            }
            else if((temp & 0x400090) == 0x400090)
            {
                std::cout << "halfword data transfer immediate\n";
            }
            else if((temp & 0x1000090) == 0x1000090)
            {
                temp << 17;
                if((temp & 0x90) == 0x90)
                {
                    std::cout << "single data swap\n";
                }
                else
                {
                    std::cout << "halfword data transfer register\n";
                }
            }
            temp << 1;
            if((temp & 0x800090) == 800090)
            {
                std::cout << "multiply long\n";
            }
            else
            {
                temp << 16;
                if((temp & 0x90) == 0x90)
                {
                    std::cout << "multiply\n";
                }
                else
                {
                    std::cout << "data processing\n";
                }
            } 
        }
    }
}