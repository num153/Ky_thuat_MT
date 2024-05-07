// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
struct SV{
    string ten;
    int maso;
    float diem;
};
typedef struct SV svien;
void nhap1sv(struct SV &sinhvien){
    fflush(stdin); // xoa bo nho dem string
    cout << "Nhap ten: "; getline(cin, sinhvien.ten);
    cout << "Nhap mssv: "; cin >> sinhvien.maso;
    cout << "Nhap diem: "; cin >> sinhvien.diem;
}
void xuat1sv(struct SV sinhvien){
    cout << "Ten: " << sinhvien.ten << endl;
    cout << "MSSV: " << sinhvien.maso << endl;
    cout << "Diem: " << sinhvien.diem << endl;
}
int main() {
    SV x;
    cout << "Nhap thong tin SV x: " << endl;
    nhap1sv(x);
    xuat1sv(x);

    return 0;
}
