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
    int chon;
    bool f=false;
    do{
        cout << "========MENU=========" << endl;
        cout << "1.Nhap he so\n2.Xuat\n3.Tinh gia tri\n4.Tong 2 da thuc\n0.Thoat\n";
        cout << "Ban chon: "; cin >> chon;
        cout << "\n=====================\n";
        switch(chon){
            case 1:
            cout << "nhap n: "; cin >> n;
                init(a,n);
                nhapHeso(a,n);
                f=true;
                break;
            case 2:
                if(f==true){
                   xuat(a,n); 
                }
                else cout << "chua co mang\n";
                break;
            case 3:
                if(f==true){
                   cout << tinhGiaTri(a,n,x) << endl; 
                }
                else cout << "chua co mang\n";
                break;
            case 4:
                if(f==true){
                   cout << "\nNhap bac m: "; cin >> m;
                    init(b,m);
                    nhapHeso(b,m);
                    xuat(b,m);
                    cout << "Tong hai ham: ";
                    tong2Dathuc(a,n,b,m);
                    break;
                }
                else cout << "chua co mang\n";
                break;    
        }
    }while(chon!=0);
    freeA(a);freeA(b);
	return 0;
}
