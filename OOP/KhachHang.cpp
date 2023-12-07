#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class KhachHang
{
    ll maKH; // Số nguyên có 5 chữ số
    string name, diachi, sdt; 
    string loaiKH; // Mua lẻ hoặc mua buôn 

    public:
        friend istream& operator >> (istream &in, KhachHang &kh)
        {
            cout << "Nhap ma khach hang: "; in >> kh.maKH; in.ignore();
            cout << "Nhap ten khach hang: "; getline(in, kh.name);
            cout << "Nhap dia chi: "; getline(in, kh.diachi);
            cout << "Nhap so dien thoai: "; getline(in, kh.sdt);
            cout << "Nhap loai khach hang: "; getline(in, kh.loaiKH);
            return in;
        }

        friend ostream& operator << (ostream &out, KhachHang &kh)
        {
            out << "----------------------------\n";
            out << "Thong tin khach hang:\n";
            out << "Ma khach hang: " << kh.maKH << endl;
            out << "Ten khach hang: " << kh.name << endl;
            out << "Dia chi: " << kh.diachi << endl;
            out << "So dien thoai: " << kh.sdt << endl;
            out << "Loai khach hang: " << kh.loaiKH << endl;
            return out;
        }
};

class MatHang
{
    ll mahang;
    string tenhang, nhomhang;
    double giaban;

    public:
        friend istream& operator >> (istream &in, MatHang &mh) // Function overloading
        {
            cout << "Nhap ma hang: "; in >> mh.mahang; in.ignore();
            cout << "Nhap ten hang: "; getline(in, mh.tenhang);
            cout << "Nhap nhom hang: "; getline(in, mh.nhomhang);
            cout << "Nhap gia ban: "; in >> mh.giaban;
            return in;
        }

        friend ostream& operator << (ostream &out, MatHang &mh)
        {
            out << "----------------------------\n";
            out << "Thong tin mat hang:\n";
            out << "Ma hang: " << mh.mahang << endl;
            out << "Ten hang: " << mh.tenhang << endl;
            out << "Nhom hang; " << mh.nhomhang << endl;
            out << "Gia ban: " << mh.giaban << endl;
            return out;
        } 
};

class BangDanhSachMuaHang
{
    set<MatHang> ds_hang;
    int so_luong_hang, so_luong_kh;
    vector<KhachHang> ds_kh;
    map<KhachHang, vector<MatHang>> ds_mua_hang;

    public: 
        vector<MatHang> nhap_ds_hang()
        {
            vector<MatHang> ds_hang;
            cout << "Nhap so luong hang: "; cin >> so_luong_hang;
            for (int i = 0; i < so_luong_hang; ++i)
            {
                MatHang mh; cin >> mh;
                this->ds_hang.insert(mh);
            }
            return ds_hang;
        }

        void in_ds_hang()
        {
            for (auto &hang : ds_hang) cout << hang;
        }

        void nhap_ds_kh()
        {
            cout << "Nhap so luong khach hang: "; cin >> so_luong_kh;
            for (int i = 0; i < so_luong_kh; ++i)
            {
                KhachHang kh; cin >> kh;
                ds_kh.push_back(kh);
                ds_mua_hang[kh] = nhap_ds_hang();
            }
        }

        void in_ds_kh()
        {
            for (auto &kh : ds_kh) cout << kh;
        }

        void in_ds_mua_hang()
        {
            for (auto &kh : ds_kh)
            {
                cout << kh;
                for (auto &hang : ds_mua_hang[kh]) cout << hang;
            }
        }

        void sap_xep_ds_mua_hang_name()
        {
            sort(ds_mua_hang.begin(), ds_mua_hang.end(), [](KhachHang &kh1, KhachHang &kh2) {return kh1. < kh2.first;} );
        }
};

int main()
{

}
