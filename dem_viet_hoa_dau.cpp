#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int demKyTu(char *s) {
	int count = 0;
	while (*s != '\0') {
		if (isalnum(*s))
			count++;
		s++;
	}
	return count;
}

char* capEach(char *s) {
	if (s != NULL) {
		if (islower(s[0]))
			s[0] = toupper(s[0]);
		for (int i = 1; i < strlen(s); i++) {
			if (isupper(s[i]))
				s[i] = tolower(s[i]);
		}
		
	}
	return s;
}

char* normalizeString(char *s) {
	char *res = new char[strlen(s)];
	res[0] = '\0';
	char *pToken = strtok(s, " ");
	while (pToken != NULL) {
		strcat(res, capEach(pToken));
		pToken = strtok(NULL, " ");
		if (pToken != NULL) {
			strcat(res, " ");
		}
	}
	return res;
}

int main() {
	char name[50];
	cout << "Nhap chuoi: " << endl;
	cin.getline(name, 50, '\n');
	/*cout << "So luong ky tu: " << demKyTu(name) << endl;

	char *pToken = strtok(name, ",");
	while (pToken != NULL) {
		cout << pToken;
		pToken = strtok(NULL, ",");
		if (pToken != NULL)
			cout << " "; 
	}
	cout << name << endl;*/
	
	char *pName = normalizeString(name);
	cout << pName << endl;
	delete []pName;
	system("pause");
}
