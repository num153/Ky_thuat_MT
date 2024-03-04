#include<iostream>
#include <ctime>
using namespace std;

void bai1(){
    int arr[3][4]={{8 ,4 ,-1 ,5},{2, 2, 6, 9},{11, 2, 5, 4}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout << arr[i][j] <<"\t"; //dung tab cach so dep hehe
    }
    cout << endl;
    }
}
void bai2(){
    int arr[4][3];
    int i=0;
    int j=0;
    while(i<4){
        j=0;
        while(j<3){
            cout << "\nNhap mang[" << i <<"][" << j << "]: ";
            cin >> arr[i][j];
            j++;
        }
        i++;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout << arr[i][j] <<"\t"; //dung tab cach so dep hehe
    }
    cout << endl;
    }
}
void bai4()
{
    int rmax=5;
    int cmax=6;
    int row,col;
    int cot,hang;
    int tongCot=0,tongHang=0;
    int arr[rmax][cmax];
    do{
        cout << "Nhap so hang(1-5): ";cin >> row;
        cout << "Nhap so cot(1-6): ";cin >> col;
    }while(row<1 || row > rmax || col<1 || row > cmax );
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << "\nNhap mang[" << i <<"][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    //in mang vua Nhap
    cout << "Mang vua nhap: \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nNhap vi tri cot tinh tong: ";cin >> cot;
    cout << "\nNhap vi tri hang tinh tong: ";cin >> hang;
    for(int i=0;i<row;i++){
            tongCot=arr[i][cot]+tongCot;
    }
    for(int j=0;j<col;j++){
            tongHang=arr[hang][j]+tongHang;
    }
    cout << "\nTong cot "<< cot << " la: " << tongCot;
    cout << "\nTong hang "<< hang << " la: " << tongHang;
    int kiem;
    bool a=false;
    int pi=0,pj=0,dem=0;
    cout << "\nNhap gia tri can kiem tra: "; cin >> kiem;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (kiem==arr[i][j]){
                pi=i;
                pj=j;
                cout << "Co vi tri: [" << pi <<"][" << pj <<"]\n";
                dem++;
            }
        }
    }
    if (dem>0){
        cout << "Lap lai " << dem << " lan\n";
    }
    else cout << "Khong ton tai trong mang\n";
}
void bai5(){
    int tongChinh=0,tongPhu=0;
    srand(time(0));
    int arr[3][3];
    //random mang cho le
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=rand() % 21;
    }
    }
    cout << "Mang vua nhap: \n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << arr[i][j] <<"\t"; //dung tab cach so dep hehe
    }
    cout << endl;
    }
    //tong duong cheo chinh
    for(int i=0;i<3;i++){
        tongChinh=tongChinh+arr[i][i];
    }
    //tong duong cheo phu
    for(int i=0;i<3;i++){
        tongPhu=tongPhu+arr[i][3-i-1];
    }
    cout << "Tong duong cheo chinh: " << tongChinh;
    cout << "\nTong duong cheo phu: " << tongPhu;
}
void bai9(){
    int bien=1;
    int n;
    cout << "Nhap kich thuoc ma tran n(2-10): ";cin >> n;
    while(n<2 || n>10){
        cout << "Nhap lai kich thuoc ma tran n(2-10): ";cin >> n;
    }
    int arr[10][10];
    for(int j=0;j<n;j++){
        if(j%2==0){
            for(int i=0;i<n;i++){
                arr[i][j]=bien++;
            }
        }else{
                for(int i=n-1;i>=0;i--){
                arr[i][j]=bien++;
            }
        }
    }
    //In mang 
    cout << "Mang vua nhap theo zigjack bro: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void bai10(){
    int bien=1;
    int n;
    cout << "Nhap kich thuoc ma tran n(2-10): ";cin >> n;
    while(n<2 || n>10){
        cout << "Nhap lai kich thuoc ma tran n(2-10): ";cin >> n;
    }
    int arr[10][10];
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                arr[i][j]=bien++;
            }
        }else{
                for(int j=n-1;j>=0;j--){
                arr[i][j]=bien++;
            }
        }
    }
    //In mang 
    cout << "Mang vua nhap theo xoan oc bro: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
