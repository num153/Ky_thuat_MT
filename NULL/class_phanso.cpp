
//=========================PHAN SO CLASS===================

#include<iostream>

using namespace std;

class PS{
    private:
    int tuso;
    int mauso;
    public:
    PS():tuso(0),mauso(1){
        
    }
    PS(int a, int b){
        tuso=a;
        mauso=b;
    }
    ~PS(){
        
    }
    void setTuso(int ts);
    void setMauso(int ms);
    int getTuso();
    int getMauso();
    void xuat(){
        cout << tuso << "/" << mauso << endl;
    }
    PS tinhTong(PS ps2);
    PS tinhHieu(PS ps2);
    PS tinhThuong(PS ps2);
};
    void PS::setTuso(int ts){
        tuso=ts;
    }
    void PS::setMauso(int ms){
        mauso=ms;
    }
    int PS::getTuso(){
        return tuso;
    }
    int PS::getMauso(){
        return mauso;
    }
    PS PS::tinhTong(PS ps2){
        PS kq;
        int tu = tuso*ps2.getMauso() + mauso*ps2.getTuso();
        int mau = mauso*ps2.getMauso();
        kq.setTuso(tu);
        kq.setMauso(mau);
        return kq;
    }
    PS PS::tinhHieu(PS ps2){
        PS kq;
        int tu = tuso*ps2.getMauso() - mauso*ps2.getTuso();
        int mau = mauso*ps2.getMauso();
        kq.setTuso(tu);
        kq.setMauso(mau);
        return kq;
    }
    PS PS::tinhThuong(PS ps2){
        PS kq;
        int tu = tuso*ps2.getMauso();
        int mau = mauso*ps2.getTuso();
        kq.setTuso(tu);
        kq.setMauso(mau);
        return kq;
    }

int main()
{
    PS ps1(2,3);
    ps1.xuat();
    PS ps2(3,2);
    ps2.xuat();
    PS ketqua=ps1.tinhTong(ps2);
    ketqua.xuat();
}
