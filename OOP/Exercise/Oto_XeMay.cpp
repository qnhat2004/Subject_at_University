#include<bits/stdc++.h>
using namespace std;

class PhuongTien
{
	float tocdo;
	
	public:
		// Constructor
		PhuongTien() {
			tocdo = 0;
		}	
		PhuongTien(float tocdo) {
			this->tocdo = tocdo;
		}
		
		// Destructor
		virtual ~PhuongTien() {}
		
		// Abstract - Pure method
		virtual float maxSpeed() = 0;
		
		// input and output
		virtual void input() {
			cin >> *this;
		}
		
		virtual void output() {
			cout << *this;
		}
		
		friend istream& operator >> (istream &in, PhuongTien &pt)
		{
			cout << "Nhap toc do: "; cin >> pt.tocdo;
			return in;
		}
		
		friend ostream& operator << (ostream &out, PhuongTien &pt)
		{
			cout << "Toc do: " << pt.tocdo << "\t";
			return out;
		}
		
		// Getter
		float getSpeed() {
			return tocdo;
		}
		
		// Operator overloading
		bool operator > (float &f) {
			return maxSpeed() > f;
		}
		
		bool operator > (PhuongTien &other) {
			return maxSpeed() > other.maxSpeed();
		}
		
		virtual bool operator == (float &f) {
			return maxSpeed() == f;
		}
};

class Oto : public PhuongTien
{
	string color;
	float heso_tocdo; // 0.0 -> 1.0
	
	public:
		// Constructor
		Oto() : PhuongTien() {
			color = "";
			heso_tocdo = 0;
		}
		
		Oto(float tocdo, string color, float heso_tocdo) : PhuongTien(tocdo) {
			this->color = color;
			this->heso_tocdo = heso_tocdo;
		}
		
		// Override
		float maxSpeed() override
		{
			return this->getSpeed() * heso_tocdo;
		}
		
		// input and output
		void input() override {
			PhuongTien::input(); cin.ignore();
			cout << "Nhap mau sac: "; getline(cin, color);
			cout << "Nhap he so toc do (0.0 -> 1.0): "; cin >> heso_tocdo;
		}
		
		void output() override {
			cout << "Kieu phuong tien: O to\t";
			PhuongTien::output();
			cout << "Mau sac: " << color << "\t";
			cout << "He so toc do: " << heso_tocdo << "\t";
			cout << "Toc do toi da: " << maxSpeed() << endl;
		}
};

class XeMay : public PhuongTien
{
	int nam_sx;
	
	public:
		// Constructor
		XeMay() : PhuongTien() {
			nam_sx = 0;
		}
		
		XeMay(float tocdo, int nam_sx) : PhuongTien(tocdo) {
			this->nam_sx = nam_sx;
		} 
		
		// Destructor
		~XeMay() {}
		
		// Override
		float maxSpeed() override
		{
			return this->getSpeed() * 0.5;
		}
		
		// input and output
		void input() {
			PhuongTien::input();
			cout << "Nhap nam san xuat: "; cin >> nam_sx;
		}
		
		void output() {
			cout << "Kieu phuong tien: Xe may\t";
			PhuongTien::output();
			cout << "Nam san xuat: " << nam_sx << "\t";
			cout << "Toc do toi da: " << maxSpeed() << endl;
		}
};

void input_amount(int &n, int Min = INT_MIN, int Max = INT_MAX)
{
	do 
	{
		cout << "Nhap so luong phuong tien: "; cin >> n;
		if (n <= Min || n >= Max)
			cout << "So luong khong hop le. Moi nhap lai!\n";
	} while (n <= Min || n >= Max);
}

void nhap(PhuongTien* &pt) {
	int choice;
	do
	{
		cout << "Ban muon nhap: 1. O to, 2. Xe may: "; cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "Lua chon khong hop le. Moi nhap lai!";
	} while (choice != 1 && choice != 2);
	
	// O to
	if (choice == 1)
	{
		pt = new Oto();
		pt->input();
	}
	
	// Xe may
	else
	{
		pt = new XeMay();
		pt->input();
	}
}

void find_minSpeed(PhuongTien **phuongtien, const int n)
{
	float min_speed = FLT_MAX;
	for (int i = 0; i < n; ++i)
		if (!(*phuongtien[i] > min_speed))
			min_speed = phuongtien[i]->maxSpeed();
	
	for (int i = 0; i < n; ++i)
		if (*phuongtien[i] == min_speed)
			phuongtien[i]->output();
}

int main()
{
	int n;
	input_amount(n, 0, 10);
	
	PhuongTien **phuongtien;
	phuongtien = new PhuongTien*[n];
	
	for (int i = 0; i < n; ++i)
	{
		cout << "\n---------------------\n";
		cout << "Nhap thong tin phuong tien thu " << i+1 << endl;
		nhap(phuongtien[i]);
	}
	
	cout << "\n---------------------\n";
	for (int i = 0; i < n; ++i)
	{
		cout << "Thong tin phuong tien thu " << i+1 << ": ";
		phuongtien[i]->output();
	}
	
	cout << "\nNhung phuong tien co toc do toi da nho nhat:\n";
	find_minSpeed(phuongtien, n);
	
	for (int i = 0; i < n; ++i)
		delete phuongtien[i];
	delete[] phuongtien;
}
