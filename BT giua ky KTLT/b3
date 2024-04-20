#include <iostream>
#include <cmath>
using namespace std;

void init(int *&a, int n){
    a = new int [n];
}
void freeArr(int *&a){
    delete []a; 
    a=nullptr;
}

void nhapHeso(int *&a, int &n){
    for(int i=n;i>=0;i--){
        cout << "x^" << i << ": ";
        cin >> a[i];
    }
}
void xuat(int *&a, int n){
    cout << "f(x): ";
    for(int i=n;i>=0;i--){
        if(i>0){
          cout << a[i] << "x^" << i << " + ";  
        }
        else cout << a[i] << endl;
    }
}
double tongFx(int *&a, int &n,double &x){
    double fx=0;
    for(int i=n;i>=0;i--){
        fx=fx+a[i]*pow(x,i);
    }
    return fx;
}
double tinh2Fx(int *&a, int &n,double &x,int *&b, int &m,double &y)


int main(){
    int *a=NULL,*b=NULL;int n,m; double x;
    cout << "Nhap bac n: "; cin >> n;
    init(a,n);
    nhapHeso(a,n);
    xuat(a,n);
    cout << "Nhap x:"; cin >> x;
    cout << "Tong f(" << x << "): " << tongFx(a,n,x) << endl;
    cout << "Nhap bac m: "; cin >> m;
    init(b,m);
    nhapHeso(b,m);
    xuat(b,m);
    
    freeArr(a);
    freeArr(b);
    system("pause");
    return 1;
}
