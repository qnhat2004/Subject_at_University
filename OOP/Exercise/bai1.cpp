#include <bits/stdc++.h>
using namespace std;

class CanBo
{
    string hoten;
    char gioitinh; // m: male, f: female
    int namsinh;

    public:
        CanBo() : hoten(""), gioitinh(' '), namsinh(0) {}
        CanBo(string hoten, char gioitinh, int namsinh)
        {
            this->hoten = hoten;
            this->gioitinh = gioitinh;
            this->namsinh = namsinh;
        }
        virtual ~CanBo() {}
        friend istream& operator >> (istream &in, CanBo &a)
        {
            cout << "Nhap ho ten: "; getline(in, a.hoten);
            cout << "Nhap gioi tinh: m-male, f-female: "; in >> a.gioitinh;
            cout << "Nhap nam sinh: "; in >> a.namsinh; in.ignore();
            return in;
        }
        friend ostream& operator << (ostream &out, CanBo &a)
        {
            cout << "----------------------------\n";
            out << "Ho ten: " << a.hoten << endl;
            out << "Gioi tinh: " << a.gioitinh << endl;
            out << "Nam sinh: " << a.namsinh << endl;
            return out;
        }
        int Tuoi() { return 2019 - namsinh; }
        virtual bool NghiHuu() = 0; // pure virtual function, abstract class
        virtual double Luong() = 0;
};

class BienChe : public CanBo
{
    string DonVi;
    double HeSoLuong;

public:
    BienChe() : DonVi(""), HeSoLuong(0), CanBo() {} 
    BienChe(string DonVi, double HeSoLuong, string hoten, char gioitinh, int namsinh) : CanBo(hoten, gioitinh, namsinh) 
    {
        this->DonVi = DonVi;
        this->HeSoLuong = HeSoLuong;
    }   
    ~BienChe() {}
    friend istream& operator >> (istream &in, BienChe &a)
    {
        // cin >> (CanBo&)a; // ép kiểu
        cout << "Nhap don vi: "; getline(in, a.DonVi);
        cout << "Nhap he so luong: "; in >> a.HeSoLuong; in.ignore();
        return in;
    }
    friend ostream& operator << (ostream &out, BienChe &a)
    {
        // cout<< (CanBo&)a; // ép kiểu
        out << "Don vi: " << a.DonVi << endl;
        out << "He so luong: " << a.HeSoLuong << endl;
        return out;
    }
    bool NghiHuu() 
    {
        return Tuoi() >= 60;
    }
    double Luong() 
    {
        double luong = HeSoLuong * 1310000;
        return (NghiHuu() ? luong * 0.7 : luong);
    }
};

class HopDong : public CanBo
{
    int namcongtac;
    double hesothamnien;
    double mucluong;

public:
    HopDong() : namcongtac(0), hesothamnien(0), mucluong(0), CanBo() {}
    HopDong(int namcongtac, double hesothamnien, double mucluong, string hoten, char gioitinh, int namsinh) : CanBo(hoten, gioitinh, namsinh)
    {
        this->namcongtac = namcongtac;
        this->hesothamnien = hesothamnien;
        this->mucluong = mucluong;
    }
    ~HopDong() {}
    friend istream& operator >> (istream &in, HopDong &a)
    {
        // cin >> (CanBo&)a; // ép kiểu, gọi hàm nhập của base class
        cout << "Nhap nam cong tac: "; in >> a.namcongtac; in.ignore();
        cout << "Nhap he so tham nien: "; in >> a.hesothamnien; in.ignore();
        cout << "Nhap muc luong: "; in >> a.mucluong; in.ignore();
        return in;
    }
    friend ostream& operator << (ostream &out, HopDong &a)
    {
        // cout << (CanBo&)a; // ép kiểu, gọi hàm xuất của base class
        out << "Nam cong tac: " << a.namcongtac << endl;
        out << "He so tham nien: " << a.hesothamnien << endl;
        out << "Muc luong: " << fixed << setprecision(4) << a.mucluong << endl;
        return out;
    }
    bool NghiHuu() 
    {
        return namcongtac >= 35;
    }
    double Luong() 
    {
        if (NghiHuu()) return 0;
        else return mucluong * hesothamnien;
    }
};

int main()
{
    int n;
    cout << "Nhap so luong can bo: "; cin >> n; cin.ignore();

    vector<CanBo*> dsCanBo(n);
    vector<BienChe> dsBienChe(n);
    vector<HopDong> dsHopDong(n);

    // Định nghĩa 1 biên chế
    for (int i = 0; i < n; ++i)
    {
        cout << "--------------\n";
        cout << "Nhap thong tin can bo thu " << i + 1 << endl;
        dsCanBo[i] = &dsBienChe[i]; 
        cin >> *dsCanBo[i] >> dsBienChe[i];
        
        dsHopDong[i] = (HopDong&)*dsCanBo[i]; // (HopDong&) ép kiểu - type casting
        cin >> dsHopDong[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "--------------\n";
        cout << "Thong tin can bo thu " << i + 1 << endl;
        dsCanBo[i] = &dsBienChe[i];
        cout << *dsCanBo[i];
        cout << dsBienChe[i];
        cout << dsHopDong[i];
        cout << "Luong: " << fixed << setprecision(4) << dsCanBo[i]->Luong() << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete dsCanBo[i];
    }
    return 0;
}
