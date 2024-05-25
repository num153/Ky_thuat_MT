#include <iostream>
#include<string>

using namespace std;

class Gio {
private:
	int gio, phut, giay;
public:
	Gio(){

	}
	Gio(int g, int p, int s) {
		gio = g;
		phut = p;
		giay = s;
	}
	~Gio() {

	}
	void set_gio(int g) {
		gio = g;
	}
	void set_phut(int p) {
		phut = p;
	}
	int get_gio() {
		return gio;
	}
	int get_phut() {
		return phut;
	}
	bool checkGioPhut() {
		return (gio >= 0 && gio <= 23) && (phut >= 0 && phut <= 59);
	}
	string ampm() {
		if (gio < 12)
			return "AM";
		else
			return "PM";
	}
	void hienthi() {
		if (checkGioPhut()) {
			cout << gio << ampm() << ":" << phut << "min:" << giay << "s" << endl;
		}
		else {
			cout << "Gio k hop le\n";
		}
	}
	void miligiay(int ms) {
		int tong_s = ms / 1000;
		gio = (tong_s / 3600) % 24;
		phut = (tong_s / 60) % 60;
		giay = tong_s % 60;
	}
};

int main() {
	Gio g1(99, 30, 50);
	g1.hienthi();
	Gio g2;
	g2.miligiay(55555000);
	g2.hienthi();
	system("pause");
	return 0;
}
