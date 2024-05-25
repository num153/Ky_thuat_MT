#include <iostream>

using namespace std;

class tamgiac {
private:
	int a, b, c;
public:
	tamgiac() {

	}
	tamgiac(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}
	~tamgiac() {

	}
	int get_a();
	int get_b();
	int get_c();
	void set_a(int x) {
		a = x;
	}
	void set_b(int y) {
		b = y;
	}
	void set_c(int z) {
		c = z;
	}

	bool checkTamgiac();
	bool can() {
		if ((a == c) || (a == b) || (b == c)) {
			return true;
		}
		else
			return false;
	}
	bool vuong() {
		if (a*a+b*b==c*c || a * a + c*c == b * b ||b * b + c * c==a*a) {
			return true;
		}
		else
			return false;
	}
	bool vuong_can() {
		if ( vuong() && can()) {
			return true;
		}
		else
			return false;
	}
	bool deu() {
		if (a==b && b==c) {
			return true;
		}
		else
			return false;
	}
	bool binhthuong() {
		if (!can() && !vuong_can() && !deu() && !vuong()) {
			return true;
		}
		else
			return false;
	}
	void kieu_tamgiac();
};
bool tamgiac::checkTamgiac() {
	if (a + b > c || a + c > b || c + b > a) {
		return true;
	}
	else {
		return false;
	}
}
void tamgiac::kieu_tamgiac() {
	if (checkTamgiac()) {
	if (deu()) cout << "Tam giac deu\n";
	if (vuong_can()) cout << "Tam giac vuong can\n";
	if (vuong()) cout << "Tam giac vuong\n";
	if (can()) cout << "Tam giac can\n";
	if (binhthuong()) cout << "Tam giac binh thuong\n";
	}
	else {
		cout << "Khong phai tam giac\n";
	}
}
int tamgiac::get_a() {
	return a;
}
int tamgiac::get_b() {
	return b;
}
int tamgiac::get_c() {
	return c;
}

int main() {
	tamgiac tg(3, 4, 5);
	tg.kieu_tamgiac();
	tamgiac tg2;
	int x, y, z;
	cout << "Nhap canh a: "; cin >> x;
	cout << "Nhap canh b: "; cin >> y;
	cout << "Nhap canh c: "; cin >> z;
	tg2.set_a(x);
	tg2.set_b(y);
	tg2.set_c(z);
	tg2.kieu_tamgiac();
	system("pause");
	return 0;
}
