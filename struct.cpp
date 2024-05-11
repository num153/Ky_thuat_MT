// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
struct Date{
    int date;
    int month;
    int year;
    Date(){}
    Date(int _d, int _m, int _y){
        date = _d;
        month=_m;
        year=_y;
    }
};
struct SV{
    //properties
    string ten;
    int maso;
    float diem;
    Date dob;
    //constructor
    SV(){}
    SV(string _name, int _ma,float _diem,Date _dob){
        ten = _name;
        maso = _ma;
        diem = _diem;
        dob = _dob;
    }
    //method
    void run(){
        cout << "...running...\n";
    }
    
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
    cout << "DOB: " << sinhvien.dob.date << "/" << sinhvien.dob.month << "/" << sinhvien.dob.year << endl;
}
int main() {
    SV x("Nam", 123,5.5, Date(15,3,2005));
    //nhap1sv(x);
    xuat1sv(x);
    x.run();

    return 0;
}

==========================================================================================

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
struct Date{
    int ngay,thang,nam;
};
struct Nhanvien{
    string hoten;
    int tuoi;
    Date date;
};

void nhap(Nhanvien ds[],int &n){
    cout << "Nhap sl nhan vien: "; cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout << "\nNhap thong tin nhan vien thu " << i+1 << endl;
        cout << "Ten: "; getline(cin, ds[i].hoten); 
        cout << "Tuoi: "; cin >> ds[i].tuoi;
        cout << "Ngay: "; cin >> ds[i].date.ngay;
        cout << "Thang: "; cin >> ds[i].date.thang;
        cout << "Nam: "; cin >> ds[i].date.nam;
        cin.ignore();
    }
}
void xuat(Nhanvien ds[],int n){
        for(int i=0;i<n;i++){
        cout << "\n\tNhan vien " << i+1 << endl;
        cout << "Ten: " << ds[i].hoten << endl;
        cout << "Tuoi: " << ds[i].tuoi << endl;
        cout << "Date: " << ds[i].date.ngay << "/" << ds[i].date.thang << "/" << ds[i].date.nam;
    }
}

int main() {
    Nhanvien ds[10];int n;
    nhap(ds,n);
    xuat(ds,n);
    return 0;
}

=============================CLASS=============================================================


// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <string>
using namespace std;

class Cat{
    private:
    string name;
    string color;
    string toy;
    public:
    void print(){
        cout << "name: " << name << endl;
        cout << "color: " << color << endl;
        cout << "toy: " << toy << endl;
    }
    //default constructor
    Cat(){
        name = "x";
        color = "x";
        toy = "x";
    }
    //constructor 3 argument
    Cat(string n, string c, string t);
};
    Cat::Cat(string n, string c, string t){
        name = n;
        color = c;
        toy = t;
    }

int main()
{   Cat cat1;
    cout << "\n====================" << endl;
    cat1.print();
    Cat cat2("Nam","Blue","HEH");
    cout << "\n====================" << endl;
    cat2.print();
    return 0;
}

