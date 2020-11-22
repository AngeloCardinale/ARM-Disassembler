#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[])
{
    std::ifstream exe(argv[1], std::ios::in|std::ios::binary|std::ios::ate);
    std::streampos size = exe.tellg();
    char* binary = new char[size];
    exe.seekg(0, std::ios::beg);
    exe.read(binary, size);
    exe.close();

    for(int i = 0; i < 32; i++) {
        std::cout << std::setfill('0') << std::setw(2) << std::right << std::hex << int(binary[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}