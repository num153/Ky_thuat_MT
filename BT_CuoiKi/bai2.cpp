
// anh nhu con thuyen khong ben doi 

#include<iostream>
#include<fstream>
using namespace std;

void ghiFile(int arr[], int n, const char* tenFile){
    ofstream outFile; 
    outFile.open("file.txt");//ios::app neu muon ghi tiep tuc 
    if(outFile.is_open()){
        for(int i=0;i<n;i++){
            outFile << arr[i] << endl;
        }
        outFile.close();
    }else{
        cout << "Khong the mo file!\n";
    }
}
void docFile(int arr[], int n, const char* tenFile){
    ifstream inFile;
    inFile("file.txt");
    if(inFile.is_open()){
        for(int i=0;i<n;i++){
            inFile >> arr[i];
        }
    }else{
        cout << "Khong the mo file\n";
    }
}
void nhapArr(int arr[], int &n){
    cout << "Nhap n: "; cin >> n;
    for(int i=0;i<n;i++){
        cout << "a[" << i << "]: ";
        cin >> arr[i];
    }
}
void xuatArr(int arr[], int n){
    cout << "Mang vua nhap: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << "\t";
    }
}
int main()
{
    int a[10];int n;
    nhapArr(a,n);
    ghiFile(a,n,"file.txt");
    docFile(a,n,"file.txt");
    xuatArr(a,n);
    return 0;
}
