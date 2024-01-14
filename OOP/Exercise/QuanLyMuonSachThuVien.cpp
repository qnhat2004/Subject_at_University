#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class BanDoc
{
	static int count_BanDoc;
	ll id;
	string name;
	string diachi;
	string sdt;
	string loai; // sinhvien, cao hoc, giang vien
	
	public:
		friend istream& operator >> (istream &in, BanDoc &bd)
		{
			bd.id = 10000 + BanDoc::count_BanDoc;
			BanDoc::count_BanDoc++;
			cout << "Ho ten: "; getline(in, bd.name);
			cout << "Dia chi: "; getline(in, bd.diachi);
			cout << "Sdt: "; getline(in, bd.sdt);
			cout << "Loai: "; getline(in, bd.loai);
			return in;
		}
		
		friend ostream& operator << (ostream &out, BanDoc &bd)
		{
			cout << "Id: " << bd.id << endl;
			cout << "Ho ten: " << bd.name << endl;
			cout << "Dia chi: " << bd.diachi << endl;
			cout << "Sdt: " << bd.sdt << endl;
			cout << "Loai: " << bd.loai << endl;
			return out;
		}
};
int BanDoc::count_BanDoc = 0;

class Sach
{
	static int count_Sach;
	ll id;
	string name;
	string tacgia;
	string chuyennganh; // Khoa hoc tu nhien, van hoc - nghe thuat, Dien tu vien thong, cong nghe thong tin
	
	public:
		friend istream& operator >> (istream &in, Sach &s)
		{
			s.id = 10000 + Sach::count_Sach;
			cout << "Ten sach: "; getline(in, s.name);
			cout << "Tac gia: "; getline(in, s.tacgia);
			cout << "Chuyen nganh: "; getline(in, s.chuyennganh);
			return in;
		}
		
		friend ostream& operator << (ostream &out, Sach &s)
		{
			cout << "Id: " << s.id << endl;
			cout << "Ten sach: " << s.name << endl;
			cout << "Tac gia: " << s.tacgia << endl;
			cout << "Chuyen nganh: " << s.chuyennganh << endl;
			return out;
		}
		
		// Nap chong toan tu so sanh de chen phan tu moi vao set
		bool operator < (const Sach &s) const
		{
			return this->id < s.id;
		}
};
int Sach::count_Sach = 0;

void input_amount(int &n)
{
	do
	{
		cout << "Nhap so luong: ";
		cin >> n;
		if (n <= 0) cout << "So lieu khong hop le. Moi nhap lai!\n";
	} while (n <= 0);
}

class Bang_QL_muon_sach
{
	set<Sach> ds_sach;
	vector<BanDoc> ds_bandoc;
	
	public:
		// 1. Nhap danh sach dau sach moi. In ra danh sach dau sach san co
		void Nhap_ds_sach()
		{
			int n;
			input_amount(n);
			
			for (int i = 0; i < n; ++i)
			{
				Sach sach;
				cout << "\n------------------\n";
				cout << "Nhap thong tin quyen sach thu " << i+1 << endl;
				cin >> sach;
				ds_sach.insert(sach);
			}
		}
		
		void In_ds_sach()
		{
			cout << "Cac loai sach co san trong kho:\n";
			int i = 1;
			for (auto sach : ds_sach)
			{
				cout << "\n------------------\n";
				cout << "Thong tin loai sach thu " << i++ << endl;
				cout << sach;
			}
		}
};

int main()
{
	Bang_QL_muon_sach bang;
	
}
