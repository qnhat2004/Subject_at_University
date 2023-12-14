#include<bits/stdc++.h>
using namespace std;

class HinhHoc
{
	string name, id;
	string type;
	
	public:
		HinhHoc() : name(""), id(""), type("") {}
		HinhHoc(string name, string id, string type) : name(name), id(id), type(type) { }	
		
		friend istream& operator >> (istream &in, HinhHoc &h)
		{
			cout << "Ten hinh: "; getline(in, h.name);
			cout << "Ma hinh: "; getline(in, h.id);
			cout << "Loai: "; getline(in, h.type);
			return in;
		}
		
		friend ostream& operator << (ostream &out, HinhHoc &h)
		{
			cout << "-------------------------\n";
			cout << "Ten hinh: " << h.name << endl;
			cout << "Ma hinh: " << h.id << endl;
			cout << "Loai: " << h.type << endl;
			return out;
		}
		
		virtual void getType() // override
		{
			cout << "Type hinh hoc" << endl; 
		}
		
		void setType(string name_type)
		{
			type = name_type;
		}
		
		void test()
		{
			getType();
		}
};

class Hcn : public HinhHoc
{
	double dai, rong;
	
	public:
		Hcn() : dai(0), rong(0) {}
		Hcn(double dai, double rong) 
		{
			this->dai = dai; 
			this->rong = rong;
			setType("Hcn");
		}
		
		friend istream& operator >> (istream &in, Hcn &h)
		{
			HinhHoc &hh = h; cin >> hh;
			cout << "Nhap chieu dai: "; in >> h.dai;
			cout << "Nhap chieu rong: "; in >> h.rong;
		}
		
		friend ostream& operator << (ostream &out, Hcn &h)
		{
			cout << "-------------------------\n";
			cout << "Dai: " << h.dai << endl;
			cout << "Rong: " << h.rong << endl;
			HinhHoc &hh = h;
			cout << hh;
		}
	
		void getType()
		{
			cout << "type hinh chu nhat\n";
		}
};

class Hv : public HinhHoc
{
	double dai, rong;
	
	public:
		
		void getType()
		{
			cout << "type hinh vuong\n";
		}
};

int main(){
	Hcn h(5, 6);
	HinhHoc *hh;
	hh = &h;

//	hh->test(); // getType() cua Hcn (neu co virtual)
	
	hh->getType();
	
	Hv hv;
	hh = &hv;
	
//	hh->test(); // getType() cua Hv

	hh->getType();
	return 0;
}
