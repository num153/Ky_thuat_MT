#define _CRT_SECURE_NO_WARNINGS
#include "kho.h"
using namespace std;

int main() {
	Kho k1;
	k1.nhap1kho();
	k1.xuat1kho();
	Kho k2;
	k2.xuat1kho();
	DsKho dsk;
	dsk.nhapDskhocontro();
	dsk.xuatDskhocontro();
	system("pause");
	return 0;
}
