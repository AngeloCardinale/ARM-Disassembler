//main for bitwise implementation
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include "printfuncts.cc"
#include "idfuncts.cc"
#include "readfuncts.cc"

using namespace std;

int main()
{
    int op1 = 0x92001510; //data processing
    int op2 = 0x0200A0E3; //data processing
    int op3 = 0x30237190; //muti
    int op4 = 0x30837190; //mutiply long
    int op5 = 0x310F4090; //Single data swap
    int op6 = 0x3E0F4080; //Coprocessor data operation

    vector<uint32_t> instructions = read("test.out");
    int i = 61;
    cout << hex << instructions.at(i * 4) << endl;
    cout << hex << instructions.at((i * 4) + 1) << endl;
    cout << hex << instructions.at((i * 4) + 2) << endl;
    cout << hex << instructions.at((i * 4) + 3) << endl;
    id(0xE3A00002);
    id(0xE12FFF1E);
}