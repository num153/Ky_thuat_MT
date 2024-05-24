#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

int tinhGiaiThua(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * tinhGiaiThua(n - 1);
}

int tinhBieuThuc1(int n, int x)
{
	double tong = 0.0;
	if (n == 1)
		return 1.0;
	else
	{
		tong = tinhBieuThuc1(n - 1, x);
		return tong + (double)tinhGiaiThua(n) / pow(x, n);
	}


}

double tinhBieuThuc2(int n)
{
	if (n == 1)
		return 1;
	else
		return sqrt(n + tinhBieuThuc2(n - 1));
}

int fibo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

void nhapMang(int a[], int& n)
{
	cout << "Nhap n: ";cin >> n;
	while (n <= 0 || n > MAX)
	{
		cout << "Vui long nhap lai!" << endl;
		cin >> n;
	}
	for (int i = 0;i < n;i++)
	{
		cout << "a[" << i << "]: "; cin >> a[i];
	}
}

void xuatMang(int a[], int n)
{
	cout << "Mang sau khi nhap la: " << endl;
	for (int i = 0;i < n;i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int demSoLe(int a[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[0] % 2 != 0)
			return 1 + demSoLe(a + 1, n - 1);
		else
			return demSoLe(a + 1, n - 1);
	}
}

int demSoChan(int a[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[0] % 2 == 0)
			return 1 + demSoChan(a + 1, n - 1);
		else
			return demSoChan(a + 1, n - 1);
	}
}

int demSoAm(int a[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[0] < 0)
			return 1 + demSoAm(a + 1, n - 1);
		else
			return demSoAm(a + 1, n - 1);
	}
}

int demSoDuong(int a[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		if (a[0] > 0)
			return 1 + demSoDuong(a + 1, n - 1);
		else
			return demSoDuong(a + 1, n - 1);
	}
}



int main()
{
	int a[MAX];
	int n, x;
	int chon;
	do
	{
		cout << "====================BAI TAP====================" << endl;
		cout << "1.Tinh bieu thuc 1" << endl;
		cout << "2.Tinh bieu thuc 2" << endl;
		cout << "3.Tinh day Fibonacci" << endl;
		cout << "4.Dem so luong so le trong mang" << endl;
		cout << "5.Dem so luong so chan trong mang" << endl;
		cout << "6.Dem so luong so am trong mang" << endl;
		cout << "7.Dem so luong so duong trong mang" << endl;
		cout << "Nhap lua chon: ";cin >> chon;
		cout << "===============================================" << endl;
		switch (chon)
		{
		case 1:
			cout << "Nhap n: ";cin >> n;
			cout << "Nhap x: ";cin >> x;
			cout << "Gia tri cua bieu thuc: " << tinhBieuThuc1(n, x) << endl;
			break;
		case 2:
			cout << "Nhap n: ";cin >> n;
			cout << "Gia tri cua bieu thuc: " << tinhBieuThuc2(n) << endl;
			break;
		case 3:
			cout << "Nhap n: ";cin >> n;
			cout << "Gia tri cua day Fibonacci: " << fibo(n) << endl;
			break;
		case 4:
			nhapMang(a, n);
			xuatMang(a, n);
			cout << "So luong so le trong mang: " << demSoLe(a, n) << endl;
			break;
		case 5:
			nhapMang(a, n);
			xuatMang(a, n);
			cout << "So luong so chan trong mang: " << demSoChan(a, n) << endl;
			break;
		case 6:
			nhapMang(a, n);
			xuatMang(a, n);
			cout << "So luong so am trong mang: " << demSoAm(a, n) << endl;
			break;
		case 7:
			nhapMang(a, n);
			xuatMang(a, n);
			cout << "So luong so duong trong mang: " << demSoDuong(a, n) << endl;
			break;
		default:
			break;
		}

	} while (chon != 0);


	system("pause");
	return 0;
}
