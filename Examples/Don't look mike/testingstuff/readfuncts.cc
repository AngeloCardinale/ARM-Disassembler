//read functions for bitwise implementation
using namespace std;

vector<uint32_t> readexe(string executable)
{
    ifstream file(executable, ios::binary);
    file.seekg(0, ios::end);
    size_t length = file.tellg();
    char* wholefile = new char[length];
    file.seekg(0, ios::beg);
    file.read(wholefile, length);
    file.close();

    vector<uint32_t> instructions;
    for (int i = 0; i < length; i+=4) 
    {
        uint32_t instruction = 0;
        for (int j = 3; j >= 0; j--) 
        {
            instruction |= wholefile[i+j] << j*8;
        }
        instructions.push_back(instruction);
    }
    return instructions;
}