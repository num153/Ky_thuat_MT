
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include <vector>
using namespace std;
void nhapTen(string& name) {
    cout << "Nhap ho ten: ";
    getline(cin, name);
}
void tachHoTen(string& name) {
    vector <string> chuoi; //tao mang luu ten vd: { dang, phuong, nam }
    char* tach = strtok((char*)name.c_str(), " ");
    while (tach != NULL) {
        chuoi.push_back(string(tach));
        tach = strtok(NULL, " ");
    }
    if (chuoi.size() > 2) {
        cout << "Ho: " << chuoi.front() << endl;
        cout << "Ho lot: ";
        for (int i = 1;i < chuoi.size() - 1;i++) {
            cout << chuoi[i] << " ";
        }
        cout << endl;
        cout << "Ten: " << chuoi.back() << endl;
    }
    else {
        cout << "Ten: " << chuoi.back() << endl;
    }
    delete[] tach;

}
void layHo(string& name) {
    char* ho = strtok((char*)name.c_str(), " ");
    cout << "Ho: " << ho;
    delete[] ho;
}
void layHolot(string& name) {
    vector <string> chuoi;
    char* tach = strtok((char*)name.c_str(), " ");
    cout << "Ho lot: ";
    while (tach != NULL) {
        chuoi.push_back(string(tach));
        tach = strtok(NULL, " ");
    }
    for (int i = 1;i < chuoi.size() - 1; i++) {
        cout << chuoi[i] << " ";
    }
    delete[] tach;
}
void layTen(string& name) {

}

int main()
{
    string hoten;
    nhapTen(hoten);
    layHolot(hoten);
    cout << "Welcome to Online IDE!! Happy Coding :)";
    return 0;
}

//===========================CACH 2 K VECTOR==========================================
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
void nhapTen(char name[]) {
    cout << "Nhap ho ten: ";
    cin.getline(name,80);
}
void tachHoten(char name[]) {
    char* tach = strtok(name, " ");
    char a[5][15];
    int n = 0;
    while (tach != NULL) {
        strcpy(a[n], tach);
        n++;
        tach = strtok(NULL, " ");
    }
    cout << "Ho: " << a[0] << endl;
    cout << "Ho lot: ";
    for (int i = 1;i < n - 1;i++) {
        cout << a[i] << " ";
    }
    cout << "\nTen: ";
    if (n >= 1) {
        cout << a[n - 1];
    }
    cout << endl;
}
int main() {
    char ten[80];
    nhapTen(ten);
    tachHoten(ten);
    return 0;
}
