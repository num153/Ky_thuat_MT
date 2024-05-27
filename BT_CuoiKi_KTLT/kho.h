#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

class Kho {
private:
	string makho;
	string tenkho;
	string diachi;
public:
	Kho() {
		makho = "";
		tenkho = "";
		diachi = "";
	}
	Kho(string mk, string tk, string dc) {
		makho = mk;
		tenkho = tk;
		diachi = dc;
	}
	~Kho() {

	}
	void set_mk(string mk) {
		makho = mk;
	}
	void set_tk(string tk) {
		tenkho = tk;
	}
	void set_dc(string dc) {
		diachi = dc;
	}
	string get_mk() {
		return makho;
	}
	string get_tk() {
		return tenkho;
	}
	string get_dc() {
		return diachi;
	}
	void nhap1kho() {
		cout << "Nhap ma kho: "; getline(cin, makho);
		cout << "Nhap ten kho: "; getline(cin, tenkho);
		cout << "Nhap dia chi: "; getline(cin, diachi);
	}
	void xuat1kho() {
		cout << "\n---------\n";
		cout << "Ma kho: " << makho << endl;
		cout << "Ten kho: " << tenkho << endl;
		cout << "Dia chi: " << diachi << endl;
	}

};
class DsKho {
private:
	vector <Kho> ds;
	Kho* a;
	int m;
public:
	void nhapDskhovector() {
		int n;
		cout << "Nhap so luong kho: "; cin >> n; cin.ignore();
		ds.resize(n);
		cout << ds.size();
		for (int i = 0;i < ds.size();i++) {
			ds[i].nhap1kho();
			//ds.push_back(ds[i]); khong can tai ds da duoc resize ve 3 phan tu roi
		}
	}
	void xuatDskhovector() {
		for (int i = 0;i < ds.size();i++)
			ds[i].xuat1kho();
	}
	void nhapDskhocontro() {
		cout << "Nhap so luong kho: "; cin >> m; cin.ignore();
		while (m <= 0 || m > 30) {
			cout << "Nhap lai: "; cin >> m; cin.ignore();
		}
		a = new Kho[m];
		for (int i = 0;i < m;i++) {
			a[i].nhap1kho();
		}
	}
	void xuatDskhocontro() {
		for (int i = 0;i < m;i++) {
			a[i].xuat1kho();
		}
	}
	void del() {
		delete[] a;
		a = nullptr;
	}
	void docFile() {
		ifstream inFile;
		inFile.open("kho.txt");
		if (inFile.is_open()) {
			inFile >> m; 
			inFile.ignore();
			a = new Kho[m];
			for (int i = 0;i < m;i++) {
				string makho;
				string tenkho;
				string diachi;
				getline(inFile, makho, '#');
				getline(inFile, tenkho, '#');
				getline(inFile, diachi);
				
				Kho k(makho, tenkho, diachi);
				a[i] = k;
			}
		}
		else
		{
			cout << "Khong mo dc file\n";
		}
	}
	void xuatTenkho() {
		for (int i = 0;i < m;i++) {
			string s = a[i].get_tk();
			if (s[0] == 'B' && s.size() <= 8) {
				a[i].xuat1kho();
			}
		}
	}
};
