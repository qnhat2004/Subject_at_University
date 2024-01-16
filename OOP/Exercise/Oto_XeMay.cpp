#include<bits/stdc++.h>
using namespace std;

class PhuongTien
{
	double tocdo;
	
	public:
		// Constructor
		PhuongTien() {
			tocdo = 0;
		}	
		PhuongTien(double tocdo) {
			this->tocdo = tocdo;
		}
		
		// Destructor
		virtual ~PhuongTien() {}
		
		// Abstract - Pure method
		virtual double maxSpeed() = 0;
		
		// input and output
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
		
		// Operator overloading
		bool operator > (const PhuongTien &other) const
		{
			return tocdo > other.tocdo;
		}
		
		// Getter
		double getSpeed() {
			return tocdo;
		}
};

class Oto : public PhuongTien
{
	string color;
	double heso_tocdo; // 0.0 -> 1.0
	
	public:
		// Constructor
		Oto() : PhuongTien() {
			color = "";
			heso_tocdo = 0;
		}
		
		Oto(double tocdo, string color, double heso_tocdo) : PhuongTien(tocdo) {
			this->color = color;
			this->heso_tocdo = heso_tocdo;
		}
		
		// Override
		double maxSpeed() override
		{
			return this->getSpeed() * heso_tocdo;
		}
		
		// input and output
		void input() {
			cin >> *(dynamic_cast<PhuongTien*>(this)); cin.ignore();
			cout << "Nhap mau sac: "; getline(cin, color);
			cout << "Nhap he so toc do (0.0 -> 1.0): "; cin >> heso_tocdo;
		}
		
		void output() {
			cout << *(dynamic_cast<PhuongTien*>(this)) << "\t";
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
		
		XeMay(double tocdo, int nam_sx) : PhuongTien(tocdo) {
			this->nam_sx = nam_sx;
		} 
		
		// Destructor
		~XeMay() {}
		
		// Override
		double maxSpeed() override
		{
			return this->getSpeed() * 0.5;
		}
		
		// input and output
		void input() {
			cin >> *(dynamic_cast<XeMay*>(this));
			cout << "Nhap nam san xuat: "; cin >> nam_sx;
		}
		
		void output() {
			cout << *(dynamic_cast<XeMay*>(this)) << "\t";
			cout << "Nam san xuat: " << nam_sx << endl;
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

void nhap(PhuongTien *pt) {
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
		dynamic_cast<Oto*>(pt)->input();
	}
	
	// Xe may
	else
	{
		pt = new XeMay();
		dynamic_cast<XeMay*>(pt)->input();
	}
}

void xuat(PhuongTien *pt)
{
	if (dynamic_cast<Oto*>(pt)) // != nullptr -> O to
	{
		Oto *oto = dynamic_cast<Oto*>(pt);
		oto->output();
	}
	else
	{
		XeMay *xemay = dynamic_cast<XeMay*>(pt);
		xemay->output();
	}
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
		xuat(phuongtien[i]);
	}
	
	for (int i = 0; i < n; ++i)
		delete phuongtien[i];
	delete[] phuongtien;
}
