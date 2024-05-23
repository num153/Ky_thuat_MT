#include<iostream>
#include <ctime>
using namespace std;
const int maxr=100;
const int maxc=100;
void nhap(int arr[maxr][maxc],int r,int c){
    cout << "Nhap gia tri cho mang " << r << " hang va " << c << " cot:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "Nhap gia tri tai vi tri [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}
void xuat(int arr[maxr][maxc],int r,int c){
    cout << "Mang vua nhap: \n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
double tb(int arr[maxr][maxc],int r,int c){
    int tong=0;
    int dem=r*c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            tong+=arr[i][j];
        }
    }
    return static_cast<double>(tong)/dem;
}
void check(int arr[maxr][maxc],int r,int c){
    int a;int dem=0;
    cout << "\nNhap gia tri can kiem tra: \n";cin >> a;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(a==arr[i][j]){
                dem++;
            }
        }
    }
    if(dem>0){
        cout << "Gia tri " << a << " co ton tai trong mang\n";
    }else cout << "Gia tri "<< a << " khong ton tai trong mang\n";
}
void doi(int &x,int &y){
    cin >> x >> y;
    cout << "\nGia tri x va y ban dau: " << x << " " << y;
    x=x^y;
    y=x^y;
    x=x^y;
    cout << "\nGia tri x va y sau doi: "<< x << " " << y;
}
int main(){
    int r,c;
    int x,y;
    double tbinh;
    int mang2chill[maxr][maxc];
    cout << "Nhap so hang: ";cin >> r;
    cout << "Nhap so cot: ";cin >> c;
    nhap(mang2chill,r,c);
    xuat(mang2chill,r,c);
    tbinh=tb(mang2chill,r,c);
    cout << tbinh;
    check(mang2chill,r,c);
    cout << "\nNhap gia tri cua x va y: ";
    doi(x,y);
}
