#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class KhachHang
{
    ll maKH; // Số nguyên có 5 chữ số
    string name, diachi, sdt; 
    string loaiKH; // Mua lẻ hoặc mua buôn 

    public:
        string getName() { return name; }

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
        
        bool operator < (KhachHang &kh) const
        {
            return this->name < kh.name;
        }
};

class MatHang
{
    ll mahang; // số nguyên có 4 chữ số, tự động tăng
    string tenhang, nhomhang; // Nhóm hàng: hàng thời trang, tiêu dùng, điện máy, gia dụng
    double giaban;

    public:
        string getTenhang() { return tenhang; }
        double getGiaban() { return giaban; }

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
        
        bool operator < (MatHang &mh) const
        {
            return this->tenhang < mh.tenhang;
        }
};

class BangDanhSachMuaHang
{
    vector<MatHang> ds_hang;
    int so_luong_hang, so_luong_kh;
    vector<KhachHang> ds_kh;
    map<KhachHang, vector<MatHang>> ds_mua_hang;
    set<MatHang> mat_hang_trong_kho;

    public: 
        void in_mat_hang_trong_kho()
        {
            cout << "Mat hang co trong kho:\n";
            for (auto hang : mat_hang_trong_kho) cout << hang;
        }

        vector<MatHang> nhap_ds_hang()
        {
            vector<MatHang> ds_hang;
            cout << "Nhap so luong hang: "; cin >> so_luong_hang;
            for (int i = 0; i < so_luong_hang; ++i)
            {
                MatHang mh; cin >> mh;
                this->ds_hang.push_back(mh);
                mat_hang_trong_kho.insert(mh);
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
                cout << "------------" << kh.getName() << "------------\n";
                for (auto &hang : ds_mua_hang[kh]) cout << hang;
            }
        }

        void sap_xep_ds_mua_hang_ten_kh()
        {
            sort(ds_kh.begin(), ds_kh.end());
        }

        void sap_xep_ds_mua_hang_ten_mat_hang()
        {
            sort(ds_mua_hang.begin(), ds_mua_hang.end());
        }

        void lap_hoa_don()
        {
            map<KhachHang, double> hoa_don;
            for (auto &kh : ds_kh)
            {
                hoa_don[kh] = 0;
                for (auto &hang : ds_mua_hang[kh])
                {
                    hoa_don[kh] += hang.getGiaban();
                }
            }
            for (auto &kh : ds_kh)
            {
                cout << kh.getName() << " " << hoa_don[kh] << endl;
            }
        }
};

int main()
{
    BangDanhSachMuaHang ds_mua_hang;

    // 1. Nhập danh sách mặt hàng mới, in ra danh sách các mặt hàng đã có
    // 2. Nhập danh sách khách hang, in ra danh sách khách hàng đã có
    ds_mua_hang.nhap_ds_kh();
    ds_mua_hang.in_ds_kh();
    
    ds_mua_hang.in_mat_hang_trong_kho();

    // 3. Lập bảng danh sach mua hàng cho từng khách hàng, in danh sách ra màn hình
    ds_mua_hang.in_ds_mua_hang();

    // 4a. Sắp xếp danh sách mua hàng theo tên khách hàng, in danh sách ra màn hình
    ds_mua_hang.sap_xep_ds_mua_hang_ten_kh();
    cout << "Danh sach mua hang sap xep theo ten khach hang:\n";
    ds_mua_hang.in_ds_mua_hang();

    // 4b. Sắp xếp theo tên mặt hàng, in danh sách ra màn hình
    ds_mua_hang.sap_xep_ds_mua_hang_ten_mat_hang();
    cout << "Danh sach mua hang sap xep theo ten mat hang:\n";
    ds_mua_hang.in_ds_mua_hang();

    // 5. Lập hóa đơn cho mỗi khách hàng
    ds_mua_hang.lap_hoa_don();

    return 0;
}
