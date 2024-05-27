/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<cstring>
#include <fstream>
using namespace std;
void bai4(char* s) {
    ofstream outFile;
    outFile.open("BT4.txt");
    if (outFile.is_open()) {
        for (int i = 0;s[i] != '\0';i++) {
            s[i] = toupper(s[i]);
        }
        outFile << s;
        outFile.close();
    }
    else
        cout << "Khong mo dc file\n";
}
void bai5(char* s) {
    int dem = 0;
    for (int i = 0;s[i] != '\0';i++) {
        if (!isspace(s[i])){
            dem++;
        }
    }
    cout << "Tong so ki tu: " << dem;
}

int main()
{
    const int n = 21;
    char chuoi[n];
    cout << "Nhap chuoi: "; cin.getline(chuoi, n);
    bai4(chuoi);
    bai5(chuoi);
    return 0;
}
