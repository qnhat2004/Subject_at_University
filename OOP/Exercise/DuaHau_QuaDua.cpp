#include <bits/stdc++.h>
using namespace std;

#define dcast dynamic_cast

class Hoaqua
{
	string id;
	string name;
	string xuatxu;
	double giathanhtien = 0;
	double gia;
	
	public:
		// Constructor
		Hoaqua() : id(""), name(""), xuatxu(""), giathanhtien(0) {}
		Hoaqua(string id, string name, string xuatxu, double giathanhtien) : id(id), name(name), xuatxu(xuatxu), giathanhtien(giathanhtien) {}
		
		// Destructor
		virtual ~Hoaqua() {}
		
		// getter and setter
		void setId(string id) {
			this->id = id;
		}
		
		string getId() {
			return id;
		}
		
		void setName(string name) {
			this->name = name; 
		}
		
		string getName() {
			return name;
		}
		
		void setXuatxu(string xx) {
			this->xuatxu = xx;
		}
		
		string getXuatxu() {
			return xuatxu;
		}
		
		virtual void setGiathanhtien(double giathanhtien) {
			this->giathanhtien = giathanhtien;
		}
		
		double getGiathanhtien() {
			return giathanhtien;
		}
		
		virtual void setGia(double gia) {
			this->gia = gia;
		}
		
		double getGia() {
			return gia;
		}
		
		// Input and output
		friend istream& operator >> (istream &in, Hoaqua &h) {
			cout << "Nhap id: "; getline(cin, h.id);
			cout << "Nhap ten: "; getline(cin, h.name);
			cout << "Nhap xuat xu: "; getline(cin, h.xuatxu);
			cout << "Nhap gia: "; cin >> h.giathanhtien;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Hoaqua &h) {
			cout << "Id: " << h.id << "\t";
			cout << "Ten hoa qua: " << h.name << "\t";
			cout << "Xuat xu: " << h.xuatxu << "\t";
			cout << "Gia: " << h.giathanhtien << "\t";
			return out;
		}
		
		// Operator overloading
		double operator + (Hoaqua &other) {
			return giathanhtien + other.giathanhtien;
		}
		
		double operator + (double a) {
			return giathanhtien + a;
		}
};

class Duahau : public Hoaqua 
{
	double kl;
	
	public:
		// Constructor
		Duahau() : Hoaqua() {}
		Duahau(string id, string name, string xuatxu, double giathanhtien, double kl) : Hoaqua(id, name, xuatxu, giathanhtien) {
			this->kl = kl;
		}
		
		// Destructor
		~Duahau() {}
		
		// Getter and setter
		void setKl(double kl) {
			this->kl = kl;
			double giamoi = kl * Hoaqua::getGia();
			Hoaqua::setGiathanhtien(giamoi);
		}
		
		double getKl() {
			return kl;
		}
		
		void setGiathanhtien(double giathanhtien) override
		{
			this->Hoaqua::setGiathanhtien(giathanhtien);
			double giamoi = (double) giathanhtien / kl;
			this->Hoaqua::setGia(giamoi);
		}
		
		void setGia(double gia) override
		{
			this->Hoaqua::setGia(gia);
			double giamoi = gia * kl;
			this->Hoaqua::setGiathanhtien(giamoi);
		}
		
		// Input and output
		friend istream& operator >> (istream &in, Duahau &d) {
			cin >> dcast<Hoaqua&>(d);
			cout << "Nhap khoi luong: "; cin >> d.kl;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Duahau &d) {
			cout << dcast<Hoaqua&>(d);
			cout << "Khoi luong: " << d.kl << "\t";
			cout << "Gia thanh tien " << d.getGiathanhtien() << endl;
		}
};

class Quadua : public Hoaqua
{
	int soluong;
	public:
		// Constructor
		Quadua() : Hoaqua() {}
		Quadua(string id, string name, string xuatxu, double giathanhtien, int soluong) : Hoaqua(id, name, xuatxu, giathanhtien) {
			this->soluong = soluong;
		}
		
		// Destructor 
		~Quadua() {}
		
		// Getter and setter
		void setSoluong(int soluong) {
			this->soluong = soluong;
			double giamoi = soluong * Hoaqua::getGia();
			Hoaqua::setGiathanhtien(giamoi);
		}
		
		double getSoluong() {
			return soluong;
		}
		
		void setGia(double gia) override
		{
			Hoaqua::setGia(gia);
			double giamoi = gia * soluong;
			Hoaqua::setGiathanhtien(giamoi);
		}
		
		void setGiathanhtien(double giathanhtien) override
		{
			Hoaqua::setGiathanhtien(giathanhtien);
			double giamoi = (double) giathanhtien / soluong;
			Hoaqua::setGia(giamoi);
		}
		
		// Input and output
		friend istream& operator >> (istream &in, Quadua &q) {
			cin >> dcast<Hoaqua&>(q);
			cout << "Nhap so luong: "; cin >> q.soluong;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Quadua &q) {
			cout << dcast<Hoaqua&>(q);
			cout << "So luong: " << q.soluong << "\t";
			cout << "Gia thanh tien: " << q.getGiathanhtien() << endl;
			return out;
		}
};

void input_amount(int &n, int Min = INT_MIN, int Max = INT_MAX) {
	do
	{
		cout << "Nhap so luong: "; cin >> n;
		if (n <= Min && n >= Max)
			cout << "So luong khong hop le. Moi nhap lai!\n";
	} while (n <= Min && n >= Max);
}

void nhap(Hoaqua* &h)
{
	int choice;
	do
	{
		cout << "Ban muon nhap: 1. Dua hau, 2. Dua: ";
		cin >> choice; 
	} while (choice != 1 && choice != 2);
	
	cin.ignore();
	
	if(choice == 1)
	{
		h = new Duahau();
		cin >> *(dcast<Duahau*>(h));
		return;
	}
	
	h = new Quadua();
	cin >> *(dcast<Quadua*>(h));
}

void xuat(Hoaqua *h)
{
	if (dcast<Duahau*>(h))
		cout << *(dcast<Duahau*>(h));
	else
		cout << *(dcast<Quadua*>(h));
}

double total(vector<Hoaqua*> h, int n)
{
	if (n == 0) return 0;
	double sum = h[0]->getGiathanhtien();
	for (int i = 1; i < n; ++i)
		sum = *(h[i]) + sum;
	return sum;
}

int main()
{
	int n;
	input_amount(n);
	
	vector<Hoaqua*> hoaqua(n);
	
	for (int i = 0; i < n; ++i)
	{
		cout << "\n-------------------------\n";
		cout << "Nhap thong tin qua thu " << i+1 << endl;
//		cin.ignore();
		nhap(hoaqua[i]);
	}
	
	cout << "\n-------------------------\n";
	for (int i = 0; i < n; ++i)
		xuat(hoaqua[i]);
	
	cout << "\nTong gia tri don hang: " << total(hoaqua, n);
	
	for (int i = 0; i < n; ++i)
		delete hoaqua[i];
}
