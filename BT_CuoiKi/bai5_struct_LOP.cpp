#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
struct Date {
	int ngay, thang, nam;
};
struct Lop {
	char malop[5]; //IT23
	char tenlop[9]; //DH23IT02
	string tenkhoa;
	int sosv;
	Date ngaykg;
};
struct DSlop {
	vector<Lop> ds;
};
bool namNhuan(int _nam) {
	if (_nam % 400 == 0 || (_nam % 4 == 0 && _nam % 100 != 0))
		return true;
	return false;
}
int tinhNgay(int _thang, int _nam) {
	int _ngay = 0;
	switch(_thang) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		_ngay = 31;
		break;
	case 4: case 6: case 9: case 11:
		_ngay = 30;
		break;
	case 2:
		if (namNhuan(_nam)) {
			_ngay = 29;
		}
		else {
			_ngay = 28;
		}
		break;
	}
}
bool checkDate(const Date ntn) {
	if (ntn.nam <= 0)
		return false;
	if (ntn.thang < 1 || ntn.thang>12)
		return false;
	if (ntn.ngay <= 0 || ntn.ngay > tinhNgay(ntn.thang, ntn.nam))
		return false; 
	return true;
}
int main() {

	system("pause");
	return 0;
}
