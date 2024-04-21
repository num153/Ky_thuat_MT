#include <iostream>
#include <cmath>
using namespace std;

void freeA(int *a){
    delete[]a; 
    a=nullptr;
}
void init(int *&a, int n){
    a = new int [n+1];
}
void xuat(int*& a, int n){
    cout << "f(x): ";
    for (int i = n; i >=0; i--)
	{
	    if(i>0){
          cout << a[i] << "x^" << i << " + ";  
        }
        else cout << a[i] << endl;
	}
}

void nhapHeso(int*& a, int n) {
	for (int i = n; i >=0; i--)
	{
		cout << "Nhap he so cua x^" << i << ": ";
		cin >> a[i];
	}
	cout << endl;
}

int tinhGiaTri(int* a, int n, int &x) {
	cout << "Nhap x: ";
	cin >> x;
	int giatri = 0;
	for (int i = n; i >=0; i--)
	{
		giatri += a[i] * pow(x, i);
	}
	cout << "f(" << x << "): ";
	return giatri;
}

void tong2Dathuc(int *a, int n, int*b, int m){
    if(n>m){
        int *c =new int [n+1];
        for(int i=m;i>=0;i--){
            c[i]=a[i]+b[i];
        }
        for(int i=n;i>m;i--){
            c[i]=a[i];
        }
        xuat(c,n);
        freeA(c);
    }
    else {
        int *c =new int [m+1];
        for(int i=n;i>=0;i--){
            c[i]=a[i]+b[i];
        }
        for(int i=m;i>n;i--){
            c[i]=b[i];
        }xuat(c,m);
        freeA(c);
    }
}


int main()
{
    int n,m,x;
    int *a=NULL;int*b=NULL;
    cout << "Nhap bac n: "; cin >> n;
    init(a,n);
    nhapHeso(a,n);
    xuat(a,n);
    //Ting f(x) tai x
    cout << tinhGiaTri(a,n,x);
    //Ting tong 2 da thuc
    cout << "\nNhap bac m: "; cin >> m;
    init(b,m);
    nhapHeso(b,m);
    xuat(b,m);
    cout << "Tong hai ham: ";
    tong2Dathuc(a,n,b,m);
    freeA(a);freeA(b);
	return 0;
}
