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
		virtual void input() {
			cout << "Nhap id: "; getline(cin, id);
			cout << "Nhap ten: "; getline(cin, name);
			cout << "Nhap xuat xu: "; getline(cin, xuatxu);
			cout << "Nhap gia: "; cin >> giathanhtien;
		}
		
		virtual void output() {
			cout << "Id: " << id << "\t";
			cout << "Ten hoa qua: " << name << "\t";
			cout << "Xuat xu: " << xuatxu << "\t";
			cout << "Gia: " << giathanhtien << "\t";
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
		void input() override {
			Hoaqua::input();
			cout << "Nhap khoi luong: "; cin >> kl;
		}
		
		void output() override {
			Hoaqua::output();
			cout << "Khoi luong: " << kl << "\t";
			cout << "Gia thanh tien " << getGiathanhtien() << endl;
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
		void input() override {
			Hoaqua::input();
			cout << "Nhap so luong: "; cin >> soluong;
		}
		
		void output() override {
			Hoaqua::output();
			cout << "So luong: " << soluong << "\t";
			cout << "Gia thanh tien: " << getGiathanhtien() << endl;
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
	
	if(choice == 1) h = new Duahau();
	else h = new Quadua();
	
	h->input();
}

double total(vector<Hoaqua*> h, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
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
		nhap(hoaqua[i]);
	}
	
	cout << "\n-------------------------\n";
	for (int i = 0; i < n; ++i)
		hoaqua[i]->output();
	
	cout << "\nTong gia tri don hang: " << total(hoaqua, n);
	
	for (int i = 0; i < n; ++i)
		delete hoaqua[i];
}
