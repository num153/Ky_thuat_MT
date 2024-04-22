
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <cmath>

using namespace std;

void nhapHeso(float &a,float &b,float &c){
    cout << "Nhap a: ";cin >> a;
    cout << "Nhap b: ";cin >> b;
    cout << "Nhap c: ";cin >> c;
    cout << "\nPT: " << a <<"x^2 + " <<b<<"x + " << c << " = 0" << endl;
}
void tinh(float &a,float &b,float &c, float delta=0.0){
    float x,x1,x2;
    if(a==0){
        if(b==0 && c!=0){
            cout << "Vo n\n";
        }
        else if(b==0 && c==0){
            cout << "vo so n\n";
        }
        else{
            x=-c/b;
            cout << "co n x=" << x << endl;
        }
    }
    else{
        delta=b*b - 4*a*c;
        if(delta<0){
            cout << "vo n\n";
        }
        else if(delta ==0){
            x=-b/(2*a);
            cout << "N kep x=" << x << endl;
        }
        else{
            x1=(-b-sqrt(delta))/(2*a);
            x2=(-b+sqrt(delta))/(2*a);
            cout << "x1= " << x1 << endl;
            cout << "x2= " << x2 << endl;
        }
    }
}

int main()
{
   float a,b,c ;
   nhapHeso(a,b,c);
   tinh(a,b,c);
}
