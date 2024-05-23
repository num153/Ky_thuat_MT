#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<cstring>
#include <fstream>
#include <vector>
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
	cout << "Diem TB: " << sv.dtb;
}
void xuatDSSV(DSSV& soluong) {
	for (int i = 0;i < soluong.n;i++) {
		cout << "\n=======Sinh vien thu " << i + 1 << " =======\n";
		xuat1SV(soluong.ds[i]);
		cout << endl;
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
void xoa1SV(DSSV& soluong, int &vt) {
	cout << "Xoa sinh vien thu: "; cin >> vt;
	for (int i = 0;i < soluong.n;i++) {
		if (i + 1 == vt) {
			for (int j = i;j < soluong.n - 1;j++) {
				soluong.ds[j] = soluong.ds[j + 1];
			}
		soluong.n--;
		}
	}
}
void themSV(DSSV& soluong, Sinhvien& svmoi) {
	if (soluong.ds == NULL) {
		soluong.n = 1;
		soluong.ds = new Sinhvien[soluong.n];
		soluong.ds[0] = svmoi;
	}
	else {
		Sinhvien* tam = soluong.ds;
		soluong.ds = new Sinhvien[soluong.n+1];
		for (int i = 0;i < soluong.n;i++) {
			soluong.ds[i] = tam[i];
		}
		soluong.ds[soluong.n] = svmoi;
		soluong.n++;
		delete[] tam;
	}
}
void update(Sinhvien& sv) {
	char lop_moi[10];
	cout << "Nhap lop moi: ";
	cin >> lop_moi;
	strcpy(sv.lop, lop_moi);
}
void xuatDSHB(DSSV soluong) {
	vector<Sinhvien> hb; //vector <kieu_du_lieu> ten_mang
	ofstream outFile;
	outFile.open("dshb.txt");
	for (int i = 0;i < soluong.n;i++) {
		if (soluong.ds[i].dtb >= 8.0) {
			hb.push_back(soluong.ds[i]);
		}
	}
	if (outFile.is_open()) {
			outFile << hb.size() << endl;
			for (int i = 0;i < hb.size();i++) {
				outFile << hb[i].ten << "#";
				outFile << hb[i].mssv << "#";
				outFile << hb[i].lop << "#";
				outFile << hb[i].dtb << endl;
			}
	outFile.close();
	}
	else {
		cout << "Khong the mo file\n";
	}
}
string getFirstName(const string& fullName) {
	int pos = fullName.find_last_of(' ');
	if (pos == string::npos) {
		return fullName; // neu k co space thi la fullname
	}
	return fullName.substr(pos + 1);//substr tach string ra
}
void xuatDSSVTheoTen(const DSSV& soluong, const string& ten) {
	cout << "Sinh vien co ten: " << ten << "la: " << endl;
	for (int i = 0; i < soluong.n; i++) {
		if (getFirstName(soluong.ds[i].ten) == ten) {
			xuat1SV(soluong.ds[i]);
			cout << endl;
		}
	}
}

int main() {
	DSSV a;
	a.ds = NULL;
	a.n = 0;
	int vt;
	int x;
	Sinhvien svm = { 2505,"Son Goku","DH23IM",8.8 };
	docDSSV(a);
	xuatDSSV(a);
	/*cout << "\nSap xep mssv giam dan: \n";
	sapxep(a, mssvDesc); 
	xoa1SV(a, vt);*/
	themSV(a, svm);
	cout << "Update sinh vien thu may: "; cin >> x;
	update(a.ds[x-1]);
	xuatDSSV(a);
	xuatDSHB(a);
	xuatDSSVTheoTen(a, "Goku");
	del(a);
	system("pause");
	return 0;
}
