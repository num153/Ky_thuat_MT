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
	switch (_thang) {
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
	return _ngay;
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
//================Nhap Xuat 1================
void nhap1lop(Lop*& l) { //co the k dung con tro cung dc
	l = new Lop;
	cout << "Nhap ma lop: ";
	cin >> l->malop; //l.malop
	cout << "Nhap ten lop: ";
	cin >> l->tenlop;
	cout << "Nhap ten khoa: ";
	cin.ignore();
	getline(cin, l->tenkhoa);
	cout << "Nhap so sv: ";
	cin >> l->sosv;
	cout << "Nhap ngay khai giang: ";
	Date ntn;
	cin >> ntn.ngay; 
	cin >> ntn.thang; 
	cin >> ntn.nam;
	if (checkDate(ntn)) {
		l->ngaykg = ntn;
	}
	else {
		cout << "Ngay k hop le\n";
	}
}
void xuat1lop(Lop *l) {
	cout << "Ma lop: " << l->malop << endl;
	cout << "Ten lop: " << l->tenlop << endl;
	cout << "Ten khoa: " << l->tenkhoa << endl;
	cout << "Ten so sv: " << l->sosv << endl;
	cout << "Ngay khai giang: ";
	if (checkDate(l->ngaykg)) {
		cout << l->ngaykg.ngay <<"/" << l->ngaykg.thang << "/" << l->ngaykg.nam << endl;
	}
	else
		cout << "Khong hop le\n";
}
//====================Nhap Xuat DS===================
void nhapDSlop(DSlop &dsl) {
	int n;
	cout << "Nhap so luong lop: ";
	cin >> n;
	cin.ignore();//bo \n di chu k co luu vao xiu nhap thong tin k dc
	for (int i = 0;i < n;i++) {
		Lop* l = nullptr;
		cout << "\nNhap lop thu " << i + 1 << endl;
		nhap1lop(l);
		dsl.ds.push_back(*l);
		delete l;
		/* neu k dung con tro
		Lop l;
		cout << "Nhap thong tin cho lop thu " << i + 1 << ":" << endl;
		nhap1lop(l);
		dsLop.ds.push_back(l);*/
	}
}
void xuatDSlop(DSlop& dsl) {
	for (int i = 0;i < dsl.ds.size();i++) {
		cout << "\n=====Lop thu " << i + 1 << "=====\n";
		xuat1lop(&dsl.ds[i]); //dsl.ds[i]
	}
}
int main() {
	DSlop dsl;
	nhapDSlop(dsl);
	xuatDSlop(dsl);
	system("pause");
	return 0;
}
