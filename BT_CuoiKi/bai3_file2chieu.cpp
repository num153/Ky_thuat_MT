
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <fstream>
using namespace std;
void init(int **&a, int &r, int &c){
    a = new int*[r];
    for(int i=0;i<r;i++){
        a[i] = new int[c];
    }
}
void del(int **&a, int r){
    for(int i=0;i<r;i++){
        delete[] a[i];
        a[i]=nullptr;
    }
    delete[]a;
    a=nullptr;
}
void nhapArr(int **&a,int &r, int &c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}
void xuatArr(int **&a, int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void ghiFile(int **&a, int r,int c, const char* tenfile){
    ofstream outFile;
    outFile.open("file.txt");
    if(outFile.is_open()){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            outFile << a[i][j] << "\t";
        }
        outFile << endl; //mot xuong dong se ghi vao cai outFile ( <-- )
    }
    outFile.close(); //Nho dong file nghe chuaaa
    }else{
        cout << "Khong the mo file\n";
    }
}
void docFile(int **&a, int r,int c, const char* tenfile){
    ifstream inFile;
    inFile.open("file.txt");
    if(inFile.is_open()){
        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            inFile >> a[i][j];
        }
    }
    inFile.close();
    }else{
        cout << "Khong the mo file\n";
    }
}
int main()
{
    int **a=NULL; int r,c;
    cout << "Nhap r: "; cin >> r;
    cout << "Nhap c: ";cin >> c;
    init(a,r,c);
    nhapArr(a,r,c);
    ghiFile(a,r,c,"file.txt");
    docFile(a,r,c,"file.txt");
    xuatArr(a,r,c);
    del(a,r);
    
    return 0;
}
