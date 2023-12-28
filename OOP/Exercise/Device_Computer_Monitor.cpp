#include <bits/stdc++.h>
using namespace std;

class Date
{
    int day, month, year;
    
    public:
        Date() : day(0), month(0), year(0) {}
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        friend istream& operator >> (istream &in, Date &date)
        {
            cout << "\tNhap ngay: "; in >> date.day;
            cout << "\tNhap thang: "; in >> date.month;
            cout << "\tNhap nam: "; in >> date.year;
            return in;
        }

        friend ostream& operator << (ostream &out, Date &date)
        {
            cout << date.day << '/' << date.month << '/' << date.year << endl;
            return out;
        }
};

class Device
{
    protected:
        int id;
        string name;
        string manufacturer; // Nha che tao
        Date importedDate; // Ngay nhap khau  

    public:
        // Constructor
        Device() : id(0), name(""), manufacturer(""), importedDate(Date()) {}
        Device(int id, string name, string manufacturer, int d, int m, int y) : id(id), name(name), manufacturer(manufacturer), importedDate(Date(d, m, y)) {}

        // Destructor
        virtual ~Device() {}

        // Getter and setter
        void setId(int id) { this->id = id; }
        int getId() const { return id; }

        void setName(string name) { this->name = name; }
        string getName() const { return name; }

        void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
        string getManufacturer() { return manufacturer; }

        void setImportedDate(int d, int m, int y) { importedDate = Date(d, m, y); }
        Date getImportedDate() { return importedDate; }

        // Input and output
        void input()
        {
            cout << "Nhap id: "; cin >> id; cin.ignore();
            cout << "Nhap name: "; getline(cin, name);
            cout << "Nhap manufacturer: "; getline(cin, manufacturer);
            cout << "Nhap importedDate:\n"; cin >> importedDate;
        }

        friend istream& operator >> (istream &in, Device &device)
        {
            device.input();
            return in;
        }

        void output()
        {
            cout << "Id: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Manufacturer: " << manufacturer << endl;
            cout << "ImportedDate: " << importedDate << endl;
        }

        friend ostream& operator << (ostream &out, Device &device)
        {
            device.output();
            return out;
        }

        virtual string toString() = 0;
};

class Computer : public Device
{
    string cpu; 
    string ram;

    public:
        // Constructor
        Computer() : Device(), cpu(""), ram("") {}
        Computer(int id, string name, string manufacturer, int d, int m, int y, string cpu, string ram) : Device(id, name, manufacturer, d, m, y), cpu(cpu), ram(ram)  {}

        // Destructor
        ~Computer() {}

        // Getter and setter
        void setCpu(string cpu) { this->cpu = cpu; }
        string getCpu() const { return cpu; }

        void setRam(string ram) { this->ram = ram; }
        string getRam() const { return ram; }

        friend istream& operator >> (istream &in, Computer &pc)
        {
            pc.Device::input();
            cin.ignore();
            cout << "Nhap cpu: "; getline(cin, pc.cpu);
            cout << "Nhap ram: "; getline(cin, pc.ram);
            return in;
        }

        friend ostream& operator << (ostream &out, Computer &pc)
        {
            pc.Device::output();
            cout << "Cpu: " << pc.cpu << endl;
            cout << "Ram: " << pc.ram << endl;
            return out;
        }

        string toString() override
        {
            return "Computer";
        }
};

class Monitor : public Device // Man hinh
{
    string size;

    public:
        // Constructor
        Monitor() : Device(), size("") {}
        Monitor(int id, string name, string manufacturer, int d, int m, int y, string size) : Device(id, name, manufacturer, d, m, y), size(size) {}

        // Destructor
        ~Monitor() {}

        // Getter and setter
        void setSize(string size) { this->size = size; }
        string getSize() const { return size; }

        // Input and output
        friend istream& operator >> (istream &in, Monitor &monitor)
        {
            monitor.Device::input();
            cin.ignore();
            cout << "Nhap size: "; getline(cin, monitor.size);
            return in;
        }

        friend ostream& operator << (ostream &out, Monitor &monitor)
        {
            monitor.Device::output();
            cout << "Size: " << monitor.size << endl;
            return out;
        }

        string toString() override
        {
            return "Monitor";
        }
};

void show_option()
{
    cout << "------------------MENU------------------\n";
    cout << "1. Nhap thong tin thiet bi\n";
    cout << "2. Hien thi thong tin thiet bi\n";
    cout << "3. Hien thi so Computer duoc nhap vao\n";
    cout << "4. Hien thi so Monitor duoc nhap vao\n";
}

void driver()
{
    cout << "------------------MENU------------------\n";
    cout << "Ban co muon tiep tuc chuong trinh?\n";
    cout << "1. Tiep tuc chuong trinh\n";
    cout << "2. Thoat chuong trinh\n";
}

int main()
{
    Device **list;
    list = new Device*[100];
    int count = 0, cnt_pc = 0, cnt_m = 0; // So thiet bi hien tai, so  pc, so monitor

    while(true)
    {
        int choice;
        show_option();
        cout << "Nhap lua chon: "; cin >> choice;

        switch(choice)
        {
            case 1:
                system("cls");
                cout << "Ban muon nhap Computer(0) hay Monitor(1): "; cin >> choice;
                if (!choice) // Computer
                {
                    list[count] = new Computer[5];
                    Computer *pc = (Computer*) list[count];
                    for (int i = 0; i < 5; ++i)
                    {
                        cout << "\n-----------------------------------\n";
                        cout << "Nhap thong tin Computer thu " << i + 1 << endl;
                        cin >> pc[i];
                    }
                    cnt_pc += 5;
                }
                else // Monitor
                {
                    list[count] = new Monitor[5];
                    Monitor *monitor = (Monitor*) list[count];
                    for (int i = 0; i < 5; ++i)
                    {
                        cout << "\n-----------------------------------\n";
                        cout << "Nhap thong tin Monitor thu " << i + 1 << endl;
                        cin >> monitor[i];
                    }
                    cnt_m += 5;
                }
                count += 5;
                break;
            
            case 2:
                for (int i = 0; i < count; ++i)
                {
                    if (list[i]->toString() == "Computer") // Computer
                    {
                        Computer *pc = (Computer*) list[i];
                        cout << "\n-----------------------------------\n";
                        cout << "Thong tin Computer thu " << i + 1 << endl;
                        cout << pc[i];
                    }
                    else // Monitor
                    {
                        Monitor *monitor = (Monitor*) list[i];
                        cout << "\n-----------------------------------\n";
                        cout << "Thong tin Monitor thu " << i + 1 << endl;
                        cout << monitor[i];
                    }
                }
                break;
            
            case 3:
                cout << "So Computer duoc nhap vao: " << cnt_pc << endl;
                break;
            
            case 4:
                cout << "So Monitor duoc nhap vao: " << cnt_m << endl;
                break;
            
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }

        driver();
        cout << "Nhap lua chon: "; cin >> choice;
        if (choice == 2) break;
    }

    // Giai phong vung nho
    for (int i = 0; i < count; ++i)
    {
        delete list[i];
    }

    delete[] list;
}
