#include<bits/stdc++.h>
using namespace std;

class NhanVien
{
	protected:
		string hoten;
		int namsinh;
		string gioitinh;
		double luong;
	public:
		// Constructor
		NhanVien() : hoten(""), namsinh(0), gioitinh(""), luong(0) {}
		NhanVien(string hoten, int namsinh, string gioitinh, double luong)
		{
			this->hoten = hoten;
			this->namsinh = namsinh;
			this->gioitinh = gioitinh;
			this->luong = luong;
		}
		
		// Destructor
		virtual ~NhanVien() {}
		
		// Getter
		string getName() {
			return hoten;
		}
		
		// Input and output
		void input()
		{
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap nam sinh: "; cin >> namsinh; cin.ignore();
			cout << "Nhap gioi tinh: "; getline(cin, gioitinh);
			cout << "Nhap luong: "; cin >> luong;
		}
		
		void output()
		{
			cout << "Ho ten: " << hoten << endl;
			cout << "Nam sinh: " << namsinh << endl;
			cout << "Gioi tinh: " << gioitinh << endl;
			cout << "Luong: " << luong << endl;
		}
		
		// Operator overloading
		friend istream& operator >> (istream &in, NhanVien &nv)
		{
			nv.input();
			return in;
		}
		
		friend ostream& operator << (ostream &out, NhanVien &nv)
		{
			nv.output();
			return out;
		}
};

class LapTrinhVien : public NhanVien
{
	string nnlt;
	
	public:
		// Constructor
		LapTrinhVien() : NhanVien(), nnlt("") {}
		LapTrinhVien(string hoten, int namsinh, string gioitinh, double luong, string nnlt) : NhanVien(hoten, namsinh, gioitinh, luong)
		{
			this->nnlt = nnlt;
		}
		
		// Destructor
		~LapTrinhVien() {}
		
		// Operator overloading
		friend istream& operator >> (istream &in, LapTrinhVien &ltv)
		{
			ltv.NhanVien::input(); cin.ignore();
			cout << "Nhap ngon ngu lap trinh: "; getline(cin, ltv.nnlt);
			return in;
		}
		
		friend ostream& operator << (ostream &out, LapTrinhVien &ltv)
		{
			ltv.NhanVien::output();
			cout << "Ngon ngu lap trinh: " << ltv.nnlt << endl;
			return out;
		}
};	

class KiemThuVien : public NhanVien
{
	string chuyenmon;
	public:
		// Constructor
		KiemThuVien() : NhanVien(), chuyenmon("") {}
		KiemThuVien(string hoten, int namsinh, string gioitinh, double luong, string chuyenmon) : NhanVien(hoten, namsinh, gioitinh, luong)
		{
			this->chuyenmon = chuyenmon;
		}
		
		// Destructor
		~KiemThuVien() {}
		
		// Operator overloading
		friend istream& operator >> (istream &in, KiemThuVien &ktv)
		{
			ktv.NhanVien::input(); cin.ignore();
			cout << "Nhap chuyen mon (kiem thu giao dien/Kiem thu chuc nang): "; getline(cin, ktv.chuyenmon);
			return in;
		}
		
		friend ostream& operator << (ostream &out, KiemThuVien &ktv)
		{
			ktv.NhanVien::output();
			cout << "Chuyen mon: " << ktv.chuyenmon << endl;
			return out;
		}
};

void print(NhanVien *nv) // Kiem tra con tro thuoc loai nao
{
	if (dynamic_cast<LapTrinhVien*>(nv)) // nv != nullptr -> Lap trinh vien
		cout << *(dynamic_cast<LapTrinhVien*>(nv));
	else
		cout << *(dynamic_cast<KiemThuVien*>(nv));
}

void Search_By_Name(const vector<NhanVien*> &dsnv, const string &name)
{
	int Size = dsnv.size();
	int count = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (name == dsnv[i]->getName())
		{
			cout << "Thong tin cua " << name << endl;
			print(dsnv[i]);
			count++;
		}
	}
	if (count == 0)
		cout << "Khong co ten trong danh sach.\n";
}

int main(){
	int n;
	do
	{
		cout << "Nhap so luong nhan vien (0 < n < 10): "; 
		cin >> n;
		if (0 >= n || n >= 10)
			cout << "So lieu khong hop le. Moi nhap lai!\n";
	} while (0 >= n || n >= 10);
	
	vector<NhanVien*> dsnv(n, nullptr);
	for (int i = 0; i < n; ++i)
	{
		cout << "\n------------------\n";
		cout << "Nhap thong tin nhan vien thu " << i+1 << endl;
		int choice;
		do
		{
			cout << "Ban muon nhap: 1. Lap trinh vien 2. Kiem thu vien: "; cin >> choice; cin.ignore();
			if (choice != 1 && choice != 2)
				cout << "So lieu khong hop le. Moi nhap lai!\n";
		} while (choice != 1 && choice != 2);
		
		if (choice == 1){
			dsnv[i] = new LapTrinhVien();
			cin >> *(dynamic_cast<LapTrinhVien*>(dsnv[i]));
		} 
		else {
			dsnv[i] = new KiemThuVien();
			cin >> *(dynamic_cast<KiemThuVien*>(dsnv[i]));
		}	
	}
	
	for (int i = 0; i < n; ++i)
	{
		cout << "\n------------------\n";
		cout << "Thong tin nhan vien thu " << i+1 << endl;
		print(dsnv[i]);
	}
	
	cout << "\n------------------\n";
	cout << "Nhap ho ten nhan vien muon tim kiem: ";
	string name; getline(cin, name);
	Search_By_Name(dsnv, name);
	
	for (int i = 0; i < n; ++i)
		delete dsnv[i];
		
	return 0;
}
