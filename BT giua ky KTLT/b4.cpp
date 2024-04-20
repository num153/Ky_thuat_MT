#include <iostream>
#include <cmath>
using namespace std;

void init(int**& a, int& r, int& c) {
    a = new int* [r];
    for (int i = 0;i < r;i++) {
        a[i] = new int[c];
    }
}
void freeArr2(int**& a, int r) {
    for (int i = 0;i < r;i++) {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[]a;
    a = nullptr;
}
void freeArr1(int*& a) {
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
//Xuat theo dieu kien (su dung flag)
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
//Vi tri dau 
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
void xuatCot(int**& a, int r, int c,int &x) {
    cout << "Nhap cot: ";cin >> x;
    int* p_cot = new int[r];
    for (int i = 0;i < r;i++) {
        p_cot[i] = a[i][x];
    }
    for (int i = 0;i < r;i++) {
        cout << p_cot[i] << "\n";
    }
    freeArr1(p_cot);
}
void xuatDong(int**& a, int r, int c, int& x) {
    cout << "Nhap dong: ";cin >> x;
    int* p_dong = new int[c];
    for (int i = 0;i < c;i++) {
        p_dong[i] = a[x][i];
    }
    for (int i = 0;i < c;i++) {
        cout << p_dong[i] << "\t";
    }
    freeArr1(p_dong);
}
void xuatCotchan(int**& a, int r, int c, int& x,bool func(int n)) {
    int* p_cot = new int[r];
    for (int i = 0;i < r;i++) {
        p_cot[i] = a[i][x];
    }
    bool flag = false;
    cout << "So chan trong cot " << x << ": ";
    for (int i = 0;i < r;i++) {
        if (!func(p_cot[i])) {
            cout << p_cot[i] << "\n";
            flag = true;
        }
    }if (flag == false) {
        cout << "k co\n";
    }
    freeArr1(p_cot);
}
void xuatCotgiam(int**& a, int r, int c, int& x) {
    int* p_cot = new int[r];
    for (int i = 0;i < r;i++) {
        p_cot[i] = a[i][x]-1;
    }
    cout << "Cot " << x << " sau khi -1: \n";
    for (int i = 0;i < r;i++) {
        cout << p_cot[i] << "\n";
    }
    freeArr1(p_cot);
}

int main() {
    int** a = NULL;int r;int c;
    int x,y;
    cout << "Nhap dong: ";cin >> r;
    cout << "Nhap cot: ";cin >> c;
    init(a, r, c);
    nhap(a, r, c);
    xuat(a, r, c);
    cout << "Tong: " << tong(a, r, c) << endl;
    cout << "So nguyen to: "; xuatDk(a, r, c, primeNum);
    cout << "\nSo le dau: "<< xuatDau(a, r, c, oddNum) << endl;
    xuatCot(a, r, c, x);
    xuatDong(a, r, c, y); cout << endl;
    xuatCotchan(a, r, c, x,oddNum);
    xuatCotgiam(a, r, c, x);
    freeArr2(a, r);
    system("pause");
    return 1;
}
