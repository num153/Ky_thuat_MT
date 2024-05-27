#define _CRT_SECURE_NO_WARNINGS
#include "kho.h"
using namespace std;

int main() {
	DsKho dsk;
	/*dsk.nhapDskhocontro();
	dsk.xuatDskhocontro();*/
	dsk.docFile();
	dsk.xuatDskhocontro();
	dsk.xuatTenkho();
	dsk.del();
	system("pause");
	return 0;
}
