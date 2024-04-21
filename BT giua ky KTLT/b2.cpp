#include<iostream>
#include <cmath>
using namespace std;
void init(int *&a, int n){
    a= new int[n];
}
void freeArr(int *a){
    delete[]a;
    a=nullptr;
}
void nhapMang(int *&a, int &n);
void xuatMang(int *&a, int n);
void p_xuatMang(int *&a, int n){
    for(int i=0;i<n;i++){
        cout << &a[i] << "\t";
    }
    cout << endl;
}
bool sqrtNum(int n);
bool perfectNum(int n);
bool am(int n){
    return n<0?true:false;
}
bool duong(int n){
    return n>0?true:false;
}
bool primeNum(int n){
    if(n<2) return false;
    else if(n>2){
        if(n%2==0) return false;
        for(int i =3; i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
    }
    return true;
}
int *min(int *&a, int n){
    int p_min=0;
    for(int i=0;i<n;i++){
        if(a[i]<a[p_min]){
            p_min=i;
            return &a[p_min];
            break;
        }
    }return NULL;
}
void removeArr(int *&a, int &n, int x){
    cout << "Nhap vi tri xoa: "; cin >> x;
    while(x>n){
        cout << "Nhap lai!"; cin >> x;
    }
    for(int i=x;i<n;i++){
        a[i]=a[i+1];
    }n--;
}
void ascendingArr(int *&a, int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                int tmp=a[j];
            a[j]=a[j+1];
            a[j+1]=tmp;
            }
        }
    }
}
void decendingArr(int *&a, int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]<a[j+1]){
                int tmp=a[j];
            a[j]=a[j+1];
            a[j+1]=tmp;
            }
        }
    }
}
void halfSort(int *&a, int &n){
    int mid = n/2;
    int *b=a+mid;
    int end=n-mid;
    ascendingArr(a,mid);
    decendingArr(b,end);
}
int* mergeArr(int *&a,int *&b,int n, int m){ //Tao mang moi roi thi nho co tra ve chu k dung void duoc nghe chua e 
    int *c;
    init(c,m+n);
    int l=0;
    for(int i=0;i<n;i++){
        c[l++]=a[i];
    }
    for(int i=0;i<m;i++){
        c[l++]=b[i];
    }
    return c;
} 
//Dem so lan theo Dieu Kien
int check(int *&a, int n, bool func(int n)){
    int count=0; 
    for(int i=0;i<n;i++){
        if(func(a[i])){
           count ++;
        }
    }
    return count;
}
//Tra ve dia chi dau tien theo Dieu Kien
int *p_Position1(int *&a, int n, bool func(int n)){
    int p=NULL;
    for(int i=0;i<n;i++){
        if(func(a[i])){
            p=i;
            return &a[p];
            break; 
        }
    }
    return NULL;
}
//Tra ve dia chi cuoi cung theo Dieu Kien
int *p_Position2(int *&a, int n, bool func(int n)){
    int p=0;
    for(int i=n-1;i>0;i--){
        if(func(a[i])){
            p=i;
            return &a[p];
            break; 
        }
    }
    return NULL;
}

int main()
{
    int *a=NULL;int *b=NULL;int *c=NULL;
    int n,m,l,x;
    cout << "Nhap n phan tu: "; cin >> n;
    init(a,n);
    nhapMang(a,n);
    ascendingArr(a,n);
    xuatMang(a,n);
    /*p_xuatMang(a,n);
    cout << "Cac so: " << check(a,n,primeNum) << endl;
    cout << "Vi tri: " << p_Position2(a,n,primeNum) << endl;
    cout << "Vi tri min: " << min(a,n) << endl;
    removeArr(a,n,x);
    xuatMang(a,n);
    cout << "Mang sau khi sap xep: \n";
    halfSort(a,n);
    xuatMang(a,n);*/
    cout << "Nhap m phan tu: "; cin >> m;
    init(b,m);
    nhapMang(b,m);
    ascendingArr(b,m);
    xuatMang(b,m);
    c = mergeArr(a,b,n,m);
    ascendingArr(c,m+n);
    xuatMang(c,m+n);
    freeArr(a);freeArr(b);freeArr(c);
}        

void nhapMang(int *&a, int &n){
    for(int i=0;i<n;i++){
        cout << "a[" << i << "]:"; cin >> a[i];
    }
}
void xuatMang(int *&a, int n){
    for(int i=0;i<n;i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
bool sqrtNum(int n){
    return (sqrt(n)*sqrt(n))==n;
}
bool perfectNum(int n){
    int s=0;
    for(int i =1;i <n; i++){
        if(n%i==0)
            s=s+i;
    }
    return s==n;
}
