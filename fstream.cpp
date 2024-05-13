
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("file.txt");
    if(inFile.fail()){
        cout << "K mo file duoc";
        return 1;
    }
    int a=0,b=0,c=0;
    while(true){
        inFile >> a >> b >> c;
        if(inFile.eof()) break;
        else{
            cout << a << b << c << endl;
        }
    }
    inFile.close();
    return 0;
}
