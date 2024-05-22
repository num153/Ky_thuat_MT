#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Sinhvien {
	long long mssv;
	string ten;
	char lop[10];
	double dtb;

};
struct DSSV {
	Sinhvien* ds; //bien a trong mang
	int n; //bien n trong a[n]
};

void nhap1SV(Sinhvien& sv) {
	cout << "Nhap ten: "; 
	 //loai bo \n sau khi nhap so luong sv
	cin.ignore();
	getline(cin, sv.ten); //getline da chua \n nen k can ignore
	cout << "Nhap mssv: "; 
	cin >> sv.mssv; 
	cin.ignore(); //loai bo \n truoc khi nhap lop
	cout << "Nhap lop: "; cin.getline(sv.lop, 10); //getline no da chua \n luon t
	cout << "Nhap diem tb: "; cin >> sv.dtb; // dtb khong con \n
}

void nhapDSSV(DSSV& soluong) {
	cout << "Nhap so luong SV: "; cin >> soluong.n;
	while (soluong.n <= 0 || soluong.n > 50) {
		cout << "Nhap lai: "; cin >> soluong.n;
	}
	soluong.ds = new Sinhvien[soluong.n]; //tuong tu cap phat bien int *a = new int[n] thoi
	for (int i = 0;i < soluong.n;i++) {
		//ham nhap thong tin tung sinh vien 
		cout << "\n======Sinh vien thu " << i +1 <<"======\n";
		nhap1SV(soluong.ds[i]);
	}

}

void del(DSSV& soluong) {
	delete[] soluong.ds;
	soluong.ds = nullptr;
}

void docDSSV(DSSV& soluong) {
	ifstream inFile;
	inFile.open("dssv.txt"); //Dang Phuong Nam#2352050#DH23IT#5.55
	if (inFile.is_open()) {
		//dong dau cua file la so luong nen cap nhat vao bien n
		inFile >> soluong.n;
		soluong.ds = new Sinhvien[soluong.n];
		for (int i = 0;i < soluong.n;i++) {
			inFile.ignore(); // bo qua \n va xuong dong thu

			//doc ten roi phan cach #
			getline(inFile, soluong.ds[i].ten,'#');
			
			//doc mssv roi ignore # o cuoi
			inFile >> soluong.ds[i].mssv;
			inFile.ignore();
			
			//doc lop roi phan cach # o cuoi
			inFile.getline(soluong.ds[i].lop, 10,'#');

			//doc dtb khi nay k con #
			inFile >> soluong.ds[i].dtb;
		}

	inFile.close();
	}
	else {
		cout << "Khong the mo file\n";
	}
}
void xuat1SV(Sinhvien sv) {
	cout << "Ten: " << sv.ten << endl;
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Lop: " << sv.lop << endl;
	cout << "Diem TB: " << sv.dtb << endl;
}
void xuatDSSV(DSSV& soluong) {
	for (int i = 0;i < soluong.n;i++) {
		cout << "\n=======Sinh vien thu " << i + 1 << " =======\n";
		xuat1SV(soluong.ds[i]);
	}
}

//===================DEM==================
int demMaLop(const DSSV& soluong, char* malop) {
	int dem = 0;
	for (int i = 0;i < soluong.n;i++) {
		if (strcmp(soluong.ds[i].lop, malop)) {
			dem++;
		}
	}
	return dem;
}
int demSVlon8(const DSSV& soluong) {
	int dem = 0;
	for (int i = 0;i < soluong.n;i++) {
		if (soluong.ds[i].dtb >=8.0) {
			dem++;
		}
	}
	return dem;
}
//===================SAP XEP================
void swap(Sinhvien& sv1, Sinhvien& sv2) {
	Sinhvien tmp;
	tmp = sv1;
	sv1 = sv2;
	sv2 = tmp;
}
int mssvDesc(Sinhvien sv1, Sinhvien sv2) {
	if (sv1.mssv > sv2.mssv) {
		return 1;
	}
	if (sv1.mssv < sv2.mssv) {
		return -1;
	}
	return 0;
}
int mssvAsc(Sinhvien sv1, Sinhvien sv2) {
	return -mssvDesc(sv1, sv2);
}

void sapxep(DSSV soluong, int funct(Sinhvien, Sinhvien)) {
	for (int i = 0;i < soluong.n - 1;i++) {
		for (int j = i + 1;j < soluong.n;j++) {
			if (funct(soluong.ds[i], soluong.ds[j]) < 0) {
				swap(soluong.ds[i], soluong.ds[j]);
			}
		}
	}
	xuatDSSV(soluong);
}
//===================Xoa Them================

int main() {
	DSSV a;
	a.ds = NULL;
	a.n = 0;
	docDSSV(a);
	xuatDSSV(a);
	cout << "Sap xep mssv giam dan: \n";
	sapxep(a, mssvDesc); 
	del(a);
	system("pause");
	return 0;
}
