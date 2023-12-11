#include <bits/stdc++.h>
using namespace std;

class sinhvien
{
//public:
    string masv, hoten;
    int tuoi;

public:
    sinhvien()
    {
        cout << "Constructor has no parameter\n";
    }
    sinhvien(string ht)
    {
        this->hoten = ht;
        cout << "Constructor sinhvien\n";
    }
    sinhvien (string ht, string msv, int tuoi)
    {
        this->hoten = ht;
        this->masv = msv;
        this->tuoi = tuoi;
        cout << "3 parameters\n";
    }

public:
    void input()
    {
        getline(cin, masv);
        getline(cin, hoten);
        cin >> tuoi; cin.ignore();
    }
    void output()
    {
        cout << "Ma sv: " << masv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class diemtongket : public sinhvien
{
public:
    // string masv, hoten;
    // int tuoi;
    double toan, ly, hoa;

    diemtongket(string name, string masv, int tuoi, double toan, double ly, double hoa) : sinhvien(name) // thuộc tính hoten = vuquangnhat ; sinhvien(vuquangnhat) -> diemtongket(vuquangnhat)
    { // Tự động gọi constructor không tham số
        sinhvien::sinhvien();
        this->toan = this->ly = this->hoa = 10;
        cout << "Name in constructor of diemtongket: " << name << endl;
        cout << "Constructor diemtongket\n";
    }
    void input()
    {
        sinhvien::input(); // Phương thức lớp cha
        cout << "Toan ly hoa: "; cin >> toan >> ly >> hoa; cin.ignore();
    }

    void output()
    {
        sinhvien::output();
        cout << "Toan ly hoa: " << toan << ' ' << ly << ' ' << hoa << ' ' << endl;
    }
};

class diemtongket2 : public sinhvien
{
    cout << sinhvien::hoten
};

int main()
{
    double toan, ly, hoa;
    diemtongket dtk("nguyen van a", "2251172445", 19, toan, ly, hoa); // sinhvien -> diemtongket, gọi constructor của lớp cha trước -> lớp con

    dtk.output();

    return 0;
}
