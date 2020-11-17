#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream test("test.out", std::ios::in|std::ios::binary|std::ios::ate);
    std::streampos size = test.tellg();
    char* binary = new char[size];
    test.seekg(0, std::ios::beg);
    test.read(binary, size);
    test.close();
    for(int i = 0; i < 32; i++)
    {
        std::cout << std::setfill('0') << std::setw(2) << std::right << std::hex << int(binary[i]) << " ";
    }
    return 0;
}