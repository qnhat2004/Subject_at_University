#include <bits/stdc++.h>
using namespace std;

class VanDongVien
{
    string hoten, monthidau;
    int tuoi;
    double chieucao, cannang;

public:
    // Constructor
    VanDongVien()
    {
        hoten = monthidau = "";
        tuoi = 0;
        chieucao = cannang = 0;
    }
    VanDongVien(string hoten, string monthidau, int tuoi, double chieucao, double cannang)
    {
        this->hoten = hoten;
        this->monthidau = monthidau;
        this->tuoi = tuoi;
        this->chieucao = chieucao;
        this->cannang = cannang;
    }

    // Destructor
    ~VanDongVien()
    {
        // delete this;
    }

    friend istream &operator >> (istream &in, VanDongVien &vdv);
    friend ostream &operator << (ostream &out, VanDongVien &vdv);

    bool operator > (const VanDongVien &vdv) const
    {
        if (this->chieucao == vdv.chieucao)
            return this->cannang > vdv.cannang;
        return this->chieucao > vdv.chieucao;
    }

    double getChieuCao() const { return chieucao; }
    double getCanNang() const { return cannang; }
};

class compare
{
    public:
        bool operator () (const VanDongVien &a, const VanDongVien &b)
        {
            return (a.getChieuCao() == b.getChieuCao()) ? (a.getCanNang() > b.getCanNang()) : (a.getChieuCao() > b.getChieuCao());
        }
};

istream &operator >> (istream &in, VanDongVien &vdv)
{
    cout << "Nhap ho ten: "; getline(in, vdv.hoten);
    cout << "Tuoi: "; in >> vdv.tuoi; in.ignore();
    cout << "Mon thi dau: "; getline(in, vdv.monthidau);
    cout << "Can nang: "; in >> vdv.cannang;
    cout << "Chieu cao: "; in >> vdv.chieucao;
    return in;
}

ostream &operator << (ostream &out, VanDongVien &vdv)
{
    out << "--------------------------------\n";
    out << "Thong tin van dong vien:\n";
    out << "Ho ten: " << vdv.hoten << endl;
    out << "Tuoi: " << vdv.tuoi << endl;
    out << "Mon thi dau: " << vdv.monthidau << endl;
    out << "Can nang: " << vdv.cannang << endl;
    out << "Chieu cao: " << vdv.chieucao << endl;
    return out;
}

void input(vector<VanDongVien> &a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

void print(const vector<VanDongVien> &a)
{
    for (auto vdv : a)
        cout << vdv;
}

int main()
{
    VanDongVien p;
    cin >> p;
    cout << p;

    int n;
    cout << "Nhap so luong van dong vien: "; cin >> n; cin.ignore();
   
    vector<VanDongVien> a(n);

    input(a, n);
    print(a);

    sort(begin(a), end(a), std::greater<VanDongVien>());

    cout << "Danh sach van dong vien sau khi sap xep chieu cao va can nang:\n";
    print(a);

}
