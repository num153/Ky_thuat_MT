
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("file.txt");
    if(inFile.fail()){
        cout << "K mo file duoc";
        return 1;
    }
    string x;
    getline(inFile, x); //lay khoang trang luon
    cout << x;
    /*int a=0,b=0,c=0;
    while(true){
        inFile >> a >> b >> c;
        if(inFile.eof()) break; //ham end of file
        else{
            cout << a << b << c << endl; // 1 2 3 /n 4 5 6
        }
    }*/
    inFile.close();
    return 0;
}
