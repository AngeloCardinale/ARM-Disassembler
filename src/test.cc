#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    bool x[32]= {0};
    x[27] = 1;
    x[24] = 1;
    for (int i = 0; i < 32;i++){
        cout << x[i]<< " ";
    }
    cout << "\n";
    for (int i = 31; i >= 0;i--){
        cout << x[i]<< " ";
    }
    cout << "\n";
    
    bool y[32]= {0};
    ifstream f;
    f.open("test.dat");
    for (int i = 0; i < 32;i++){
        f >> y[i];
    }

     for (int i = 0; i < 32;i++){
        cout << y[i]<< " ";
    }

}