#include <bits/stdc++.h>
using namespace std;

class MayIn
{
    int id;
    string hang;

    public:
        // Constructor
        MayIn() : id(0), hang("") {}
        MayIn(int id, string hang) : id(id), hang(hang) {}

        // Destructor
        virtual ~MayIn() {}

        // Getter and Setter
        void setID(int id) { this->id = id; }
        int getID() const { return this->id; }

        void setHang(string hang) { this->hang = hang; }
        string getHang() { return this->hang; }

        // Nhap xuat
        void input()
        {
            cout << "Nhap id: "; cin >> id; cin.ignore();
            cout << "Nhap hang: "; getline(cin, hang);
        }

        void output()
        {
            cout << "ID: " << id << endl;
            cout << "Hang: " << hang << endl;
        }

        // Ham thuan ao - pure method
        virtual bool chatLuongCao() = 0;
};

class MayInKim : public MayIn
{
    int soKim;

    public:
        // Constructor
        MayInKim() : MayIn(), soKim(0) {}
        MayInKim(int id, string hang, int soKim) : MayIn(id, hang), soKim(soKim) {}

        // Destructor
        ~MayInKim() {}
        
        // Getter and Setter
        void setSoKim(int sokim) { 
			this->soKim = sokim; 
		}
		int getSoKim() const {
			return this->soKim;	
		}
		
		// Input and Output
		friend istream& operator >> (istream &in, MayInKim &mik)
		{
			mik.MayIn::input();
			cout << "Nhap so kim: "; cin >> mik.soKim;
		}
		
		friend ostream& operator << (ostream& out, MayInKim &mik)
		{
			mik.MayIn::output();
			cout << "So kim: " << mik.soKim << endl;
		}
		
		// Override
		bool chatLuongCao() override 
		{
			return this->soKim >= 24;
		}
};

class MayInLaser : public MayIn
{
	int dpg; // do phan giai
	
	public:
		// Constructor
		MayInLaser() : MayIn(), dpg(0) {}
		MayInLaser(int id, string hang, int dpg) : MayIn(id, hang), dpg(dpg) {}
		
		// Destructor
		~MayInLaser() {}
		
		// Getter and Setter
        void setDPG(int dpg)
        {
            this->dpg = dpg;
        }
		
        int getDPG()
        {
            return this->dpg;
        }

        // Input and Output
        friend istream& operator >> (istream &in, MayInLaser &mil)
        {
            mil.MayIn::input();
            cout << "Nhap do phan giai: "; cin >> mil.dpg;
            return in;
        }

        friend ostream& operator << (ostream &out, MayInLaser &mil)
        {
            mil.MayIn::output();
            cout << "Do phan giai: " << mil.dpg << endl;
            return out;
        }

        bool chatLuongCao() override
        {
            return this->dpg >= 1200;
        }
};

int main()
{
	int n;
    
    do
    {
        cout << "Nhap so luong may in: "; cin >> n;
        if (n <= 0 || n >= 10) 
        {
            cout << "So luong khong hop le. Nhap lai." << endl;
        }
    } while (n <= 0 || n >= 10);

    vector<MayIn*> dsMayIn(n);
    vector<int> choices(n);

    for (int i = 0; i < n; ++i)
    {
        int choice;
        do
        {
            cout << "\n---------------------------\n";
            cout << "Ban muon nhap may in kim(0) hay may in laser(1)? ";
            cin >> choice;
            cout << "\n---------------------------\n";
            if (choice != 0 && choice != 1)
                cout << "Lua chon khong hop le. Moi nhap lai.\n";
        } while (choice != 0 && choice != 1);
        
        if (!choice) // may in kim
        {
            dsMayIn[i] = new MayInKim();
            MayInKim *mik = (MayInKim*) dsMayIn[i]; // lay noi dung cua con tro dsMayIn[i] - hien dang luu tru dia chi vung nho dau tien cua lop cha - lop MayIn
            cout << "\n---------------------------\n";
            cout << "Nhap thong tin may in kim:\n";
            cin >> *mik; 
        }

        else // may in laser
        {
            dsMayIn[i] = new MayInLaser(); // Tro con tro dsMayIn[i] den vung nho co kieu du lieu MayInLaser o vung nho heap
            MayInLaser *mil = (MayInLaser*) dsMayIn[i]; // Tro con tro mil den cung dia chi voi con tro dsMayIn[i]
            cout << "\n---------------------------\n";
            cout << "Nhap thong tin may in laser:\n";
            cin >> *mil; // cin: nhap thong tin vao noi dung cua dia chi ma con tro dang tro den, mil la con tro luu tru dia chi
        }

        choices[i] = choice;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "\n---------------------------\n";
        cout << "Thong tin may in thu " << i + 1 << ":\n";
        if (!choices[i]) // may in kim
        {
            cout << "May in kim\n";
            MayInKim *mik = (MayInKim*) dsMayIn[i];
            cout << *mik;
        }
        else // may in laser
        {
            cout << "May in Laser\n";
            MayInLaser *mil = (MayInLaser*) dsMayIn[i];
            cout << *mil;
        }
    }

    // Giai phong vung nho
    for (int i = 0; i < n; ++i)
    {
        delete dsMayIn[i];
    }

	return 0;
}
