
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
void tinhTong(int **&a, int r, int c){
    int s=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            s+=a[i][j];
        }
    }
    cout << "Tong: " << s << endl;
}
int timMax(int **&a, int r, int c,int i, int j, int max=0){
    if(i==r){
        return max;
    }
    if(a[i][j] > max){
        max = a[i][j];
    }
    if(j<c-1){
        return timMax(a,r,c,i,j+1);
    }else{
        return timMax(a,r,c,i+1,0);
    }
}
int main()
{
    int **a=NULL; int r,c,i,j;
    int max=0;
    cout << "Nhap r: "; cin >> r;
    cout << "Nhap c: ";cin >> c;
    init(a,r,c);
    nhapArr(a,r,c);
    ghiFile(a,r,c,"file.txt");
    docFile(a,r,c,"file.txt");
    xuatArr(a,r,c);
    tinhTong(a,r,c);
    cout << "Gia tri max: " << timMax(a,r,c,i,j,max);
    del(a,r);
    
    return 0;
}
