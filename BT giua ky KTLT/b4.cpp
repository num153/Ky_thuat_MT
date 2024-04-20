#include <iostream>
#include <cmath>
using namespace std;

void init(int**& a, int& r, int& c) {
    a = new int* [r];
    for (int i = 0;i < r;i++) {
        a[i] = new int[c];
    }
}
void freeArr(int**& a, int r) {
    for (int i = 0;i < r;i++) {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[]a;
    a = nullptr;
}

void nhap(int**& a, int& r, int& c) {
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}
void xuat(int**& a, int r, int c) {
    cout << "Mang: " << endl;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cout << a[i][j] << "\t";
        }cout << endl;
    }
}
int tong(int**& a, int& r, int& c) {
    int s = 0;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            s = s + *(*(a + i) + j); //a[i*c + j] Kieu nay cung duoc nhe e
        }
    }
    return s;
}
bool primeNum(int n) {
    if (n < 2) return false;
    else if (n > 2) {
        if (n % 2 == 0) return false;
        for (int i = 3;i <= sqrt(n);i++) {
            if (n % i == 0) return false;
        }
    }
    return true;
}
bool oddNum(int n) {
    return n % 2 != 0;
}
//Xuat theo dieu kien
void xuatDk(int**& a, int r, int c, bool func(int n)) {
    bool flag = false;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (func(a[i][j])) {
                cout << a[i][j] << " ";
                flag = true;
            }
        }
    }if (flag==false) {
        cout << "Khong co\n";
    }
}
//Vi tri dau theo dieu kien
int *xuatDau(int**& a, int r, int c, bool func(int n)) {
    int pi = NULL, pj = NULL;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (func(a[i][j])) {
                pi = i;
                pj = j;
                return &a[pi][pj];
                break;
            }
        }
    }return NULL;

}

int main() {
    int** a = NULL;int r;int c;
    cout << "Nhap dong: ";cin >> r;
    cout << "Nhap cot: ";cin >> c;
    init(a, r, c);
    nhap(a, r, c);
    xuat(a, r, c);
    cout << "Tong: " << tong(a, r, c) << endl;
    cout << "So nguyen to: "; xuatDk(a, r, c, primeNum);
    cout << "\nSo le dau: "<< xuatDau(a, r, c, oddNum) << endl;
    freeArr(a, r);
    system("pause");
    return 1;
}
