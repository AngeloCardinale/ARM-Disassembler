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
    vector<uint32_t> instructions = readexe("test.out");
    int i = 61;
    cout << hex << instructions.at(i * 4) << endl;
    cout << hex << instructions.at((i * 4) + 1) << endl;
    cout << hex << instructions.at((i * 4) + 2) << endl;
    cout << hex << instructions.at((i * 4) + 3) << endl;
    id(0xE3A00002);
    id(0xE12FFF1E);
}