#include <iostream>

int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x30237190; //muti
    int op3 = 0x30837190; //mutiply long

    int temp = op2;
    temp = temp >> 4;                                                   //Bit shift past first 4 unnecessary bits
    
    if((temp & 0x0000001)== 0x0000001)                                  //1st bit is 1
    {
        if((temp & 0x0000009)== 0x0000009)                              //1st 4 bits are 1001
        {
            temp = temp >> 4;
           
                if((temp & 0x0FF00F) == 0x010000 ||(temp & 0x0FF00F)== 0x014000)
                {
                    std::cout << "single data swap\n";
                }
                else if((temp & 0x0E400F) == 0x000000)
                {
                    std::cout << "Halfword data transfer register offset\n";
                }

                temp = temp >> 12;

                if((temp & 0x0F8) == 0x008)
                {
                    std::cout << "multiply long\n";
                }
                else if((temp & 0x0FC) == 0x000)
                {
                    std::cout << "multiply \n";
                }
                
        }
        else if((temp & 0x012FFF1) == 0x012FFF1)                        //Check if Branch and Exchange
        {
            std::cout << "branch and exchange\n";
        }
        else if((temp & 0x0E40009) == 0x0E40009)
        {
            std::cout << "Halfword data transfer immediate offset\n";
        }
        else if((temp & 0x0E40009) == 0x0E00009)
        {
            std::cout << "Halfword data transfer register offset\n";
        }

        temp = temp >> 20;

        if((temp & 0x0F) == 0x0F)                                  //27th to 24th bits are 1111
        {
            std::cout << "Software interrupt\n";                
        }   

        else if((temp & 0x0E) == 0x0E)                                  //27th to 24th bits are 1110
        {
            std::cout << "Coprocessor register transfer\n";                
        }  

        else if((temp & 0x0C) == 0x00)
        {
            std::cout << "Data processing\n";
        }          
        else if((temp & 0x0E) == 0x0C)  
        {
            std::cout << "Coprocessor data transfer\n";
        } 
         else if((temp & 0x0E) == 0x0A)  
        {
            std::cout << "branch\n";
        }     
         else if((temp & 0x0E) == 0x08)  
        {
            std::cout << "Block data transfer\n";
        }   
        else if((temp & 0x0C) == 0x04)  
        {
            std::cout << "Single data transfer\n";
        }                                                         
        
    }
    else                                                                //first bit is 0
    {
        temp = temp >> 20;
        if((temp & 0x0E) == 0x0E)                                       //27th to 24th bits are 1110
        {
            std::cout << "Coprocessor data operation\n";                
        }
        else if((temp & 0x0F) == 0x0F)                                  //27th to 24th bits are 1111
        {
            std::cout << "Software interrupt\n";                
        }                    
        else if((temp & 0x0C) == 0x00)
        {
            std::cout << "Data processing\n";
        }          
        else if((temp & 0x0E) == 0x0C)  
        {
            std::cout << "Coprocessor data transfer\n";
        } 
         else if((temp & 0x0E) == 0x0A)  
        {
            std::cout << "branch\n";
        }     
         else if((temp & 0x0E) == 0x08)  
        {
            std::cout << "Block data transfer\n";
        }   
        else if((temp & 0x0C) == 0x04)  
        {
            std::cout << "Single data transfer\n";
        }   
    }
}


    