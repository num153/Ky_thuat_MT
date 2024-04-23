#include<iostream>
#include <cmath>
using namespace std;
void init(int*& a, int n) {
    a = new int[n];
}
void freeArr(int* a) {
    delete[]a;
    a = nullptr;
}
void nhapMang(int*& a, int& n);
void xuatMang(int*& a, int n);
void p_xuatMang(int*& a, int n) {
    for (int i = 0;i < n;i++) {
        cout << &a[i] << "\t";
    }
    cout << endl;
}
bool sqrtNum(int n);
bool perfectNum(int n);
bool am(int n) {
    return n < 0 ? true : false;
}
bool duong(int n) {
    return n > 0 ? true : false;
}
bool primeNum(int n) {
    if (n < 2) return false;
    else if (n > 2) {
        if (n % 2 == 0) return false;
        for (int i = 3; i <= sqrt(n);i++) {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
int* min(int*& a, int n) {
    int p_min = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] < a[p_min]) {
            p_min = i;
            return &a[p_min];
            break;
        }
    }return NULL;
}
void removeArr(int*& a, int& n, int &x) {
    cout << "Nhap vi tri xoa: "; cin >> x;
    while (x > n) {
        cout << "Nhap lai!"; cin >> x;
    }
    for (int i = x;i < n-1;i++) {
        a[i] = a[i + 1];
    }n--;
}
void addArr(int*& a, int& n, int &x) {
     for(int i = n; i > x; i--){
        a[i] = a[i-1];
    }
    // Chen val tai pos
    a[x] = val;
    // Tang so luong phan tu sau khi chen.
    ++n;
}

void ascendingArr(int*& a, int n) {
    for (int i = n - 1;i > 0;i--) {
        for (int j = 0;j < i;j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void decendingArr(int*& a, int n) {
    for (int i = n - 1;i > 0;i--) {
        for (int j = 0;j < i;j++) {
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void halfSort(int*& a, int& n) {
    int mid = n / 2;
    int* b = a + mid;
    int end = n - mid;
    ascendingArr(a, mid);
    decendingArr(b, end);
}
int* mergeArr(int*& a, int*& b, int &n, int &m) { //Tao mang moi roi thi nho co tra ve chu k dung void duoc nghe chua e 
    int* c;
    init(c, m + n);
    int l = 0;
    for (int i = 0;i < n;i++) {
        c[l++] = a[i];
    }
    for (int i = 0;i < m;i++) {
        c[l++] = b[i];
    }
    return c;
}
//Dem so lan theo Dieu Kien
int check(int*& a, int n, bool func(int n)) {
    int count = 0;
    for (int i = 0;i < n;i++) {
        if (func(a[i])) {
            count++;
        }
    }
    return count;
}
//Tra ve dia chi dau tien theo Dieu Kien
int* p_Position1(int*& a, int n, bool func(int n)) {
    int p = NULL;
    for (int i = 0;i < n;i++) {
        if (func(a[i])) {
            p = i;
            return &a[p];
            break;
        }
    }
    return NULL;
}
//Tra ve dia chi cuoi cung theo Dieu Kien
int* p_Position2(int*& a, int n, bool func(int n)) {
    int p = 0;
    for (int i = n - 1;i > 0;i--) {
        if (func(a[i])) {
            p = i;
            return &a[p];
            break;
        }
    }
    return NULL;
}

int main()
{
    int* a = NULL;int* b = NULL;int* c = NULL;
    int n, m, l, x;
    int chon;
    do {
        cout << "\n====================BAI TAP====================" << endl;
        cout << "1.Nhap mang" << endl;
        cout << "2.Xuat mang" << endl;
        cout << "3.Dem so chinh phuong" << endl;
        cout << "4.Kiem tra so hoan thien" << endl;
        cout << "5.Kiem tra so am" << endl;
        cout << "6.Kiem tra so duong" << endl;
        cout << "7.Kiem tra so nguyen to" << endl;
        cout << "8.Dia chi so chinh phuong dau tien trong mang" << endl;
        cout << "9.Dia chi so hoan thien cuoi cung trong mang" << endl;
        cout << "10.Dia chi so nho nhat dau tien trong mang" << endl;
        cout << "11.Dia chi so nho nhat cuoi cung trong mang" << endl;
        cout << "12.Xoa 1 phan tu khoi mang" << endl;
        cout << "13.Sap xep mang giam dan" << endl;
        cout << "14.Sap xep mang tang dan" << endl;
        cout << "15.Sap xep nua dau mang tang dan va nua sau mang giam dan" << endl;
        cout << "16.Gop 2 mang" << endl;
        cout << "17.Gop 2 mang tang dan thanh 1 mang cung tang dan" << endl;
        cout << "0.Thoat!" << endl;
        cout << "Nhap lua chon: ";cin >> chon;
        cout << "===============================================" << endl;
        switch (chon) {
        case 1:
            nhapMang(a, n);
            break;
        case 2: 
            xuatMang(a, n);
            break;
        case 3: 
            cout << "So chinh phuong: " << check(a, n, sqrtNum) << endl;
            break;
        case 4: 
            cout << "so hoan thien: " << check(a, n, perfectNum) << endl;
            break;
        case 5: 
            cout << "so am: " << check(a, n, am) << endl;
            break;
        case 6:
            cout << "so duong: " << check(a, n, duong) << endl;
            break;
        case 7: 
            cout << "so nguyen to: " << check(a, n, primeNum) << endl;
            break;
        case 8:
            cout << "dia chi chinh phuong dau: " << p_Position1(a, n, sqrtNum);
            break;
        case 9: 
            cout << "dia chi hoan thien cuoi: " << p_Position2(a, n, perfectNum);
            break;
        case 10: 
            cout << "nho nhat dau tien: " << min(a, n);
            break;
        case 11: 
            cout << "nho nhat cuoi mang";
        case 12:
            cout << "xoa phan tu"; removeArr(a, n, x);
            break;
        case 13:
            cout << "giam dan: "; decendingArr(a, n); xuatMang(a, n);
            break;
        case 14:
            cout << "tang dan: "; ascendingArr(a, n); xuatMang(a, n);
            break;
        case 15:
            cout << "nua dau tang sau giam: "; halfSort(a, n);
            break;
        case 16:
            nhapMang(a, n);
            xuatMang(a, n);
            nhapMang(b, m);
            xuatMang(b, m);
            c = mergeArr(a, b, n, m);
            cout << "gop 2 mang: "; xuatMang(c, m + n);
            free(a);
            free(b);
            free(c);
            break;
        case 17:
            nhapMang(a, n);
            xuatMang(a, n);
            nhapMang(b, m);
            xuatMang(b, m);
            cout << "gop 2 mang tang dan: ";
            c = mergeArr(a, b, n, m);
            ascendingArr(c, n + m);
            xuatMang(c, m + n);
            free(a);
            free(b);
            free(c);
            break;
        default:
            cout << "khong co trong menu!";
            break;
        }
    } while (chon != 0);

}

void nhapMang(int*& a, int& n) {
    cout << "Nhap n: "; cin >> n;
    init(a, n);
    for (int i = 0;i < n;i++) {
        cout << "a[" << i << "]:"; cin >> a[i];
    }
}
void xuatMang(int*& a, int n) {
    for (int i = 0;i < n;i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
bool sqrtNum(int n) {
    return (sqrt(n) * sqrt(n)) == n;
}
bool perfectNum(int n) {
    int s = 0;
    for (int i = 1;i < n; i++) {
        if (n % i == 0)
            s = s + i;
    }
    return s == n;
}
