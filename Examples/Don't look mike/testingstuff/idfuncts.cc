//id functions for bitwise implementation
using namespace std;

// the dov input
bool check_bits(uint32_t instruction, uint32_t mask, uint32_t expected) {
    return (instruction & mask) == expected;
}

bool bitcheck(uint32_t num, uint32_t pos)
{
    return((num >> (pos - 1)) & 1);
}

void id(uint32_t instruction)
{
    uint32_t type;
    bool bits[32];
    for(int i = 1; i <= 32; i++)
    {
        bits[i - 1] = bitcheck(instruction, i);
    }
    if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == true && bits[23] == false && bits[22] == false 
    && bits[21] == true && bits[20] == false && bits[19] == true && bits[18] == true && bits[17] == true && bits[16] == true 
    && bits[14] == true && bits[13] == true && bits[12] == true && bits[11] == true && bits[10] == true && bits[9] == true 
    && bits[8] == true && bits[7] == false && bits[6] == false && bits[5] == false && bits[4] == true) //branch and exchange
    {
        branchandex(instruction);
    }
    else if((bits[27] == false && bits[26] == false) && (bits[7] == false || bits[4] == false)) //data processing
    {
        dataprocessing(instruction);
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == false && bits[23] == false && bits[22] == false 
    && bits[7] == true && bits[6] == false && bits[5] == false && bits[4] == true) //multi
    {
        multiply(instruction);
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == false && bits[23] == true && bits[7] == true 
    && bits[6] == false && bits[5] == false && bits[4] == true) //mutli long
    {
        multiplylong(instruction);
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[24] == true && bits[23] == false && bits[21] == false 
    && bits[20] == false && bits[11] == false && bits[10] == false && bits[9] == false && bits[8] == false && bits[7] == true 
    && bits[6] == false && bits[5] == false && bits[4] == true) //single data swap
    {
        singledataswap(instruction);
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[22] == false && bits[11] == false && bits[10] == false 
    && bits[9] == false && bits[8] == false && bits[7] == true && bits[4] == true) //Half data transfer reg offset
    {
        halfdatatransreg(instruction);
    }
    else if(bits[27] == false && bits[26] == false && bits[25] == false && bits[22] == true && bits[7] == true && bits[4] == true) //Half data transfer immediate
    {
        halfdatatransimm(instruction);
    }
    else if(bits[27] == false && bits[26] == true) //single word transfer
    {
        singledatatrans(instruction);
    }
    else if(bits[27] == true && bits[26] == false && bits[25] == false) //block data transfer
    {
        blockdatatrans(instruction);
    }
    else if(bits[27] == true && bits[26] == false && bits[25] == true) //branch
    {
        branch(instruction);
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == false) //coprocessor data transfer
    {
        coprodatatrans(instruction);
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == false && bits[4] == false) //coprocessor data operation
    {
        coprodataop(instruction);
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == false && bits[4] == true) //coprocessor register transfer
    {
        coproregtrans(instruction);
    }
    else if(bits[27] == true && bits[26] == true && bits[25] == true && bits[24] == true) //software interupt
    {
        softwareinterrupt(instruction);
    }
    else //bad instruction
    {
        cout << "bad instruction\n";
    }
}