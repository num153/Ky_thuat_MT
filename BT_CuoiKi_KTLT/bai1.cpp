
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
    cout << "So cau: " << dem << endl;
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
    cout << "So tu: " << dem << endl;
    // tuy nhien xin chao,con cai,ai << 3 ?
}
void check(string s, bool func(string s)){
    if(func(s)){
        cout << "Co\n";
    }
    else cout << "Khong\n";
}
int main()
{   
    string str; char x; int chon;
    cout << "Nhap chuoi: "; getline(cin, str);
    check(str,isNum);
    cout << str << endl;
    do{
        cout << "\n============@_@============\n";
        cout << "1. Kiem tra co so khong\n";
        cout << "2. Kiem tra co space dau va cuoi khong\n";
        cout << "3. Tach bo space\n";
        cout << "4. Tach tung chu\n";
        cout << "5. Dem so cau\n";
        cout << "6.Dem so tu\n";
        cout << "7. Dem so dau cau\n";
        cout << "8. Tra ve ten dia phuong ung voi 3 ki tu dau\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch(chon){
            case 1:
                check(str,isNum);
                break;
            case 2:
                check(str,spaceDauCuoi);
                break;
            case 3: 
                xoaSpaceDauCuoiGiua(str);
                cout << str;
                break;
            case 4:
                tachToken(str,x);
                break;
            case 5:
                demCau(str);
                break;
            case 6:
                demSotu(str);
                break;
            case 7:
                break;
            case 8:
                break;
        }
    }while(chon!=0);
    return 0;
}
