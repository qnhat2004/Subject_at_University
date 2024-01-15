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
			cout << "Id: " << bd.id << "\t";
			cout << "Ho ten: " << bd.name << "\t";
			cout << "Dia chi: " << bd.diachi << "\t";
			cout << "Sdt: " << bd.sdt << "\t";
			cout << "Loai: " << bd.loai << endl;
			return out;
		}
		
		bool operator == (BanDoc &other)
		{
			return (this->name == other.name && this->diachi == other.diachi && this->sdt == other.sdt && this->loai == other.loai);
		}
		
		bool operator < (BanDoc &other)
		{
			return this->id < other.id;
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
			cout << "Id: " << s.id << "\t";
			cout << "Ten sach: " << s.name << "\t";
			cout << "Tac gia: " << s.tacgia << "\t";
			cout << "Chuyen nganh: " << s.chuyennganh << endl;
			return out;
		}
		
		// Operator overloading
		bool operator == (const Sach &sach)
		{
			return (this->name == sach.name && this->tacgia == sach.tacgia && this->chuyennganh == sach.chuyennganh);
		}
		
		bool operator < (const Sach &other)
		{
			return this->id < other.id;
		}
};
int Sach::count_Sach = 0;

template<class E, class V>
bool is_exist(E element, const V &Vector) // Kiem tra lieu doi tuong da ton tai trong vung chua hay chua
{
	for (auto i : Vector)
		if (i == element)
			return true;
	return false;
}



class Bang_QL_muon_sach
{
	vector<Sach> ds_sach;
	vector<BanDoc> ds_bandoc;
	map<BanDoc, vector<pair<Sach, int>>> bandoc_muonsach; // Bandoc - ten dau sach - so luong dau sach do
	
	public:
		void input_amount(int &n, int right = INT_MAX)
		{
			do
			{
				cout << "Nhap so luong: ";
				cin >> n;
				if (n <= 0 && n > right) cout << "So lieu khong hop le. Moi nhap lai!\n";
			} while (n <= 0 && n > right);
		}
		
		// 1. Nhap danh sach dau sach moi. In ra danh sach dau sach san co
		void Nhap_ds_sach()
		{
			cout << "Nhap cac dau sach co san trong kho:\n";
			int n;
			input_amount(n); cin.ignore();
			
			for (int i = 0; i < n; ++i)
			{
				Sach sach;
				cout << "\n------------------\n";
				cout << "Nhap thong tin quyen sach thu " << i+1 << endl;
				cin >> sach;
				if (!is_exist<Sach, vector<Sach>>(sach, ds_sach)) // Neu chua co trong danh sach ban dau
					ds_sach.push_back(sach);
			}
		}
		
		void In_ds_sach()
		{
			cout << "\n------------------\n";
			cout << "Cac loai sach co san trong kho:\n";
			int i = 1;
			for (auto sach : ds_sach)
			{
				cout << "Thong tin loai sach thu " << i++ << ":\t";
				cout << sach;
			}
		}
		
		// 2. Nhap danh sach ban doc. In ra danh sach ban doc da co
		void nhap_ds_ban_doc()
		{
			cout << "\nNhap so luong ban doc:\n";
			int n; 
			input_amount(n); cin.ignore();
			
			for (int i = 0; i < n; ++i)
			{
				cout << "\n------------------\n";
				cout << "Nhap thong tin ban doc thu " << i+1 << endl;
				BanDoc bandoc; cin >> bandoc;
				ds_bandoc.push_back(bandoc);
			}
		}
		
		void in_ds_ban_doc()
		{
			cout << "\n------------------\n";
			cout << "Danh sach ban doc:\n";
			int i = 1;
			for (auto bandoc : ds_bandoc)
			{
				cout << "Thong tin ban doc thu " << i++ << ":\t";
				cout << bandoc;
			}
		}
		
		// 3. Lap bang quan ly muon sach cho tung ban doc bang cach nhap cac dau sach ban doc muon, va in ra danh sach len man hinh
		int sach_isExist(const BanDoc &bandoc, const Sach &sach) // Tra ve vi tri dau sach trong ds muon cua ban doc do, neu khong ton tai tra ve -1
		{
			int Size = bandoc_muonsach[bandoc].size();
			for (int i = 0; i < Size; ++i)
				if (bandoc_muonsach[bandoc][i].first == sach)
					return i;
			return -1;
		} 
		
		void nhap_ds_muon()
		{
			cout << "\n------------------\n";
			cout << "Nhap thong tin muon sach cho cac ban doc:\n";
			for (BanDoc bandoc : ds_bandoc)
			{
				cout << "Thong tin muon sach cua ban doc " << bandoc << ":\n";
				cout << "Nhap so luong dau sach (0 <= n <= 5): ";
				int n; input_amount(n, 5);
				for (int i = 0; i < n; ++i)
				{
					cout << "Nhap thong tin loai sach thu " << i+1 << endl;
					Sach sach; cin >> sach;
					int index = sach_isExist(bandoc, sach);
					if (index != -1)
						bandoc_muonsach[bandoc][index].second++;
					else
						bandoc_muonsach[bandoc].push_back({sach, 0});
				}
			}
		}
};

int main()
{
	Bang_QL_muon_sach bang_ql_muon_sach;
	
	// 1. Nhap danh sach dau sach moi. In ra danh sach dau sach san co
	bang_ql_muon_sach.Nhap_ds_sach();
	bang_ql_muon_sach.In_ds_sach();
	
	// 2. Nhap danh sach ban doc. In ra danh sach ban doc da co
	bang_ql_muon_sach.nhap_ds_ban_doc();
	bang_ql_muon_sach.in_ds_ban_doc();
	
	
}
