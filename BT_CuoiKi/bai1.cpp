
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <string>
#include <cctype>
using namespace std;

bool isNum(string s){
    for(char c : s){
        if(isdigit(c)){
            return true;
        }
    }
    return false;
}
bool spaceDauCuoi(string s){
    if(isspace(s[0]) || isspace(s.length()-1)){
        return true;
    }
    else return false;
}
void xoaSpaceDauCuoiGiua(string &s){
    //xoa space dau 
    while(s[0] == ' '){
        s.erase(0,1);
    }
    //xoa space cuoi 
    while(s[s.length()-1]==' '){
        s.erase(s.length()-1,1);
    }
    //xoa space giua
    int i=0;
    while(!s.empty() && i<s.length()){
        if(s[i] == ' ')
        {
        s.erase(i,1);
        }
        else i++;
    }
}
void tachToken(string &s, char &kitu){
    cout << "Nhap ki tu: "; cin >> kitu; cin.ignore();
    char *p = strtok((char*)s.c_str(),&kitu); //ep kieu string ve char* moi su dung dc c-string
    while(p!=NULL){
        cout << p << endl;
        p = strtok(NULL,&kitu); //tai sao lai them may cai & ???
    }
}
void demCau(string &s){
    int dem=0;
    for(char c: s){
        if(c == '.' || c == '!' ||c == '?'){
            dem++;
        }
    }
    cout << "So cau: " << dem;
}
void demDaucau(string &s){
    int dem =0;
    
}
void demSotu(string &s){
    int dem=0;
    if(s[0] != ' '){
        dem=1;
    }
    for(int i=1;i<s.length();i++){
        if(s[i-1] == ' ' && s[i] != ' '){
            dem++;   
    }
    }
    cout << "So tu: " << dem;
}
void check(string s, bool func(string s)){
    if(func(s)){
        cout << "Co\n";
    }
    else cout << "Khong\n";
}
int main()
{   
    string str; char x;
    cout << "Nhap chuoi: "; getline(cin, str);
    check(str,isNum);
    cout << str << endl;
    demCau(str);
    demSotu(str);
    return 0;
}
