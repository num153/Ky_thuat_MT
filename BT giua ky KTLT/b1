#include<iostream>
#include <cmath>
using namespace std;

void nhap(int a, int b, int c){
    cout << "Nhap he so cho phuong trinh: \n"; cout << "a: "; cin >> a;
    cout << "\nb: "; cin >> b; cout << "\nc: ";cin >> c;
    cout << "PT: " << a << "x^2 + " << b << "x + " << c << endl;
}
void tinh(int a, int b, int c, int delta=0){
    delta = b*b - 4*a*c;
    if (delta > 0) {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co 2 nghiem phan biet:\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    } else if (delta == 0) {
        float x = -b / (2 * a);
        cout << "Phuong trinh co nghiem kep:\n";
        cout << "x = " << x << "\n";
    } else {
        cout << "Phuong trinh vo nghiem\n";
    }
}

int main()
{
    int a, b, c, delta;
    nhap(a,b,c);
    tinh(a,b,c);
    
}              
