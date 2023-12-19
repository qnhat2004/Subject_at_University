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
        	cout << "------------------------------\n";
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
        
        bool operator < (const KhachHang &kh) const
        {
        	return name < kh.name;
		}
};

class MatHang
{
    ll mahang; // Số nguyên có 4 chữ số, tự động tăng
    string tenhang, nhomhang; // Nhóm hàng: hàng thời trang, tiêu dùng, điện máy, gia dụng
    double giaban;

    public:
        string getTenhang() { return tenhang; }
        double getGiaban() { return giaban; }
        
        friend istream& operator >> (istream &in, MatHang &mh) // Function overloading
        {
        	cout << "-------------------------------\n";
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
        bool operator< (const MatHang &mh) const
        {
            return tenhang < mh.tenhang;
        }
};

// class compareKhachHang
// {
// public:
//     bool operator ()(const KhachHang &kh1, const KhachHang &kh2) const
//     {
//         return kh1.getName() < kh2.getName();
//     }
// };

// class compareMatHang
// {
// public:
//     bool operator () (const MatHang &mh1, const MatHang &mh2) const
//     {
//         return mh1.getTenhang() < mh2.getTenhang();
//     }
// };

class BangDanhSachMuaHang
{
    public:
        vector<KhachHang> ds_kh;
        map<KhachHang, vector<MatHang>> ds_mua_hang;
        set<MatHang> mat_hang_trong_kho;

    public:
    	void nhap_mat_hang_trong_kho()
    	{
    		int so_luong_mh;
    		cout << "Nhap so luong mat hang trong kho: "; cin >> so_luong_mh;
    		for (int i = 0; i < so_luong_mh; ++i)
    		{
    			cout << "------------Nhap mat hang thu " << i + 1 << "------------\n" << endl;
    			MatHang mh; cin >> mh;
    			mat_hang_trong_kho.insert(mh);
			}
		}
        void in_mat_hang_trong_kho()
        {
            cout << "-------------Cac mat hang co san trong kho:--------------\n";
            for (auto hang : mat_hang_trong_kho) cout << hang;
        }

        vector<MatHang> nhap_ds_hang() // Nhập danh sách hàng cần mua của 1 khách hàng 1 khách hàng
        {
            vector<MatHang> ds_hang;
            int so_luong_hang; // Số lượng hàng cần mua của mỗi khách hàng
            cout << "-------Nhap so luong mat hang:---------"; cin >> so_luong_hang;
            for (int i = 0; i < so_luong_hang; ++i)
            {
                MatHang mh; cin >> mh;
                ds_hang.push_back(mh);
                mat_hang_trong_kho.insert(mh); // Thêm m?t hàng này vào kho (set)
            }
            return ds_hang;
        }

        void in_ds_hang()
        {
            for (auto &kh : ds_kh)
            {
                cout << "------------" << kh.getName() << "--------------\n";
                for (auto &hang : ds_mua_hang[kh]) 
                    cout << hang;
            }
        }

        void nhap_ds_kh()
        {
            int so_luong_kh; // Số lượng khách hàng
            cout << "-----------------Nhap so luong khach hang:-----------------"; cin >> so_luong_kh;
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

//         void sap_xep_ds_mua_hang_ten_kh()
//         {
//             sort(ds_kh.begin(), ds_kh.end(), compareKhachHang);
//         }

        // void sap_xep_ds_mua_hang_ten_mat_hang(KhachHang &kh)
        // {
        //     sort(ds_mua_hang[kh].begin(), ds_mua_hang[kh].end(), compareMatHang);
        // }

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
            cout << "Hoa don cua tung khach hang:\n";
            for (auto &kh : ds_kh)
            {
                cout << kh.getName() << ": " << hoa_don[kh] << endl;
            }
        }
};

int main()
{
    BangDanhSachMuaHang ds_mua_hang;

    // 1. Nhập danh sách mặt hàng mới, in ra danh sách các mặt hàng dã có
    ds_mua_hang.nhap_mat_hang_trong_kho();
    ds_mua_hang.in_mat_hang_trong_kho();
    
    // 2. Nhập danh sách khách hàng, in ra danh sách khách hàng dã có
    ds_mua_hang.nhap_ds_kh();
    ds_mua_hang.in_ds_kh();

    // 3. Lập bảng danh sach mua hàng cho từng khách hàng, in danh sách ra màn hình
    ds_mua_hang.in_ds_mua_hang();

    // // 4a. Sắp xếp danh sách mua hàng theo tên khách hàng, in danh sách ra màn hình
    // ds_mua_hang.sap_xep_ds_mua_hang_ten_kh();
    // cout << "Danh sach mua hang sap xep theo ten khach hang:\n";
    // ds_mua_hang.in_ds_mua_hang();

    // // 4b. Sắp xếp theo tên mặt hàng, in danh sách ra màn hình
    // for (auto &kh : ds_mua_hang)
    //     sap_xep_ds_mua_hang_ten_mat_hang(kh);
    // cout << "Danh sach mua hang sap xep theo ten mat hang:\n";
    // ds_mua_hang.in_ds_mua_hang();

    // 5. L?p hóa don cho m?i khách hàng
    ds_mua_hang.lap_hoa_don();

    return 0;
}
