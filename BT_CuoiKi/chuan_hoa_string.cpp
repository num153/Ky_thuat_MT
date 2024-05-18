#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void xoaDauCuoi(string &s){
    //Xoa khoang trang dau & cuoi 
    while(!s.empty() && s[0] == ' '){
        s.erase(0,1);
    }
    while(!s.empty() && s[s.length()-1] == ' '){
        s.erase(s.length()-1,1);
    }
}
void xoa2Space(string &s){
    //Moi tu chi cach nhau mot khoang trang
    int i=0;
    while(!s.empty() && i<s.length()){
        if(s[i] == ' ' && s[i+1] == ' ')
        {
        s.erase(i,1); //Vi tri se tu don ve phia truoc va cap nhat
        }
        else i++;
    }
}
void inHoadau(string &s){
    //chuyen chuoi thanh in thuong het
    for(int i =0;i<s.length();i++){
        s[i] = tolower(s[i]);
    }
    //viet hoa dau moi tu
    for(int i=0;i<s.length();i++){
        if(i == 0 || s[i-1] == ' ' && isalpha(s[i])){
            s[i] = toupper(s[i]);
        }
    }
}

int main() {
    string str;
    cout << "Nhap chuoi: "; getline(cin, str);
    xoaDauCuoi(str);
    cout << "Chuoi sau khi xoa space dau va cuoi: \n" << str << endl;
    xoa2Space(str);
    cout << "Chuoi sau khi xoa cac khoang trang thua: \n" << str << endl;
    inHoadau(str);
    cout << "Chuoi sau khi viet hoa tu dau tien: \n" << str << endl;
    return 0;
}
