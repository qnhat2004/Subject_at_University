#include <bits/stdc++.h>
using namespace std;

class ConNguoi
{
	protected:
		string hoten;
		int tuoi;

	public:
		ConNguoi() : hoten(""), tuoi(0) {}
		ConNguoi(string hoten, int tuoi) : hoten(hoten), tuoi(tuoi) {}
		virtual ~ConNguoi() {}
		virtual void input() = 0;
		virtual void output() = 0;
		virtual bool KhenThuong() = 0;
};

class SinhVien : public ConNguoi
{
	string lop;
	double dtb;

	public:
		SinhVien() : ConNguoi(), lop(""), dtb(0) {}
		SinhVien(string hoten, int tuoi, string lop, double dtb) : ConNguoi(hoten, tuoi), lop(lop), dtb(dtb) {}
		~SinhVien() {}
		void input() override
		{
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap tuoi: "; cin >> tuoi;
			cin.ignore();
			cout << "Nhap lop: "; getline(cin, lop);
			cout << "Nhap diem trung binh: "; cin >> dtb;
		}
		void output() override
		{
			cout << "Ho ten: " << hoten << endl;
			cout << "Tuoi: " << tuoi << endl;
			cout << "Lop: " << lop << endl;
			cout << "Diem trung binh: " << dtb << endl;
		}
		bool KhenThuong() override
		{
			return dtb >= 8.0;
		}
};

class GiangVien : public ConNguoi
{
	string bomon;
	int sobaibao;

	public:
		GiangVien() : ConNguoi(), bomon(""), sobaibao(0) {}
		GiangVien(string bomon, int sobaibao, string hoten, int tuoi) : ConNguoi(hoten, tuoi), bomon(bomon), sobaibao(sobaibao) {}
		~GiangVien() {}
		void input() override
		{
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap tuoi: "; cin >> tuoi;
			cin.ignore();
			cout << "Nhap bo mon: "; getline(cin, bomon);
			cout << "Nhap so bai bao: "; cin >> sobaibao;
		}
		void output() override
		{
			cout << "Ho ten: " << hoten << endl;
			cout << "Tuoi: " << tuoi << endl;
			cout << "Bo mon: " << bomon << endl;
			cout << "So bai bao: " << sobaibao << endl;
		}
		bool KhenThuong() override
		{
			return sobaibao >= 1;
		}
};

int main()
{
	ConNguoi *connguoi;

	int n; 
	cout << "Nhap so luong sinh vien: ";
	cin >> n; cin.ignore();

	connguoi = new SinhVien[n];
	SinhVien *temp = (SinhVien*) connguoi;

	for (int i = 0; i < n; ++i)
	{
		cout << "\n----------------------\n";
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
		(temp+i)->input();
		cin.ignore();
		temp = temp + i;
	}
	cout << "Thong tin sinh vien duoc khen thuong:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "\n----------------------\n";
		if (connguoi[i].KhenThuong())
		{
			cout << "Thong tin sinh vien thu " << i + 1 << ":" << endl;
			connguoi[i].output();
		}
	}
	delete[] connguoi;

	int m;
	cout << "Nhap so luong giang vien: ";
	cin >> m; cin.ignore();

	connguoi = new GiangVien[m];
	for (int i = 0; i < m; ++i)
	{
		cout << "\n----------------------\n";
		cout << "Nhap thong tin giang vien thu " << i + 1 << ":" << endl;
		connguoi[i].input();
		cin.ignore();
	}
	for (int i = 0; i < m; ++i)
	{
		cout << "\n----------------------\n";
		if (connguoi[i].KhenThuong())
		{
			cout << "Thong tin giang vien thu " << i + 1 << ":" << endl;
			connguoi[i].output();
		}
	}
	delete[] connguoi;

	return 0;
}
