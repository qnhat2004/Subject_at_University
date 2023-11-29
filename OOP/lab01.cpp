#include <bits/stdc++.h>
using namespace std;

class TLClass
{
    string ID;
    string name; // Tên lớp học
    string description;
    // Miêu tả về lớp học này
    string position; // Vị trí của lớp học

    public:
        void input()
        {
            cout << "Nhap ID: "; cin >> ID;
            cout << "Nhap ten lop hoc: "; cin >> name; cin.ignore();
            cout << "Nhap mo ta lop hoc: "; getline(cin, description);
            cout << "Nhap vi tri lop hoc: "; getline(cin, position);
        }
        string getID()
        {
            return ID;
        }     
        string getName()
        {
            return name;
        } 
        string getDescription()
        {
            return description;
        }
        string getPosition()
        {
            return position;
        }
        void output()
        {
            cout << "ID: " << getID() << endl;
            cout << "Class name: " << getName() << endl;
            cout << "Description: " << getDescription() << endl;
            cout << "Position: " << getPosition() << endl;
        }
};

class TLStudent
{ 
    string name; // Tên sinh viên 
    string address; // Địa chỉ nhà
    string description; // Miêu tả về sinh viên này
    double note; // Điểm tổng kết của sinh viên
    TLClass tlClass; // Lớp của sinh viên này
    string id; 

    public:
        void input()
        {
            cout << "Nhap ID sinh vien: "; cin >> id; cin.ignore();
            cout << "Nhap ten sinh vien: "; getline(cin, name);
            cout << "Nhap dia chi: "; getline(cin, address);
            cout << "Nhap mo ta: "; getline(cin, description);
            cout << "Nhap lop hoc: "; tlClass.input();
        }
        string getID()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        string getAddress()
        {
            return address;
        }
        string getDescription()
        {
            return description;
        }
        TLClass getClass()
        {
            return tlClass;
        }
        double getNote()
        {
            return note;
        }
        void output()
        {
            cout << "ID: "; cout << getID() << endl;
            cout << "Student name: " << getName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "Description: " << getDescription() << endl;
            cout << "Descripton of class: "; getClass().output();
            cout << "Final grade: " << getNote() << endl;
        }
};

class StudentManagement
{
    public:
        map<string, vector<TLStudent>> Class; // Các lớp học

    public:
        // 1. Thêm mới sinh viên 
        void addStudent()
        {
            while(true)
            {
                TLStudent student;
                student.input();
                student.output();
                Class[student.getClass()].push_back(student);
            }
        }
        // 2. Xóa sinh viên khỏi danh sách
        void removeStudent(string id)
        {
            for (auto & cl : Class.first)
                if (student.getID == id)
                {
                    // cl.erase(std::remove(begin(Class), end(Class), student), cl.end());
                    cl.erase(this->student);
                    return;
                }
        }
        // 3. Tìm kiếm sinh viên theo mã
        void searchByID (string id)
        {
            bool check = false;
            for (auto & cl : Class)
            {
                for (auto &student : cl)
                {
                    if (student.id == id)
                    {
                        student.output();
                        return;
                    }
                }
            }
            if (!check) cout << "Khong tim thay sinh vien co id như vay\n";
        }
        // 4. Liệt kê danh sách tất cả sinh viên
        // Liệt kê sinh viên trong lớp
        void listStudentOfClass(TLClass &cl)
        {
            for (auto &student : cl)
            {
                student.output();
            }
        }
        void listAllStudent () // Liệt kê tất cả sinh viên trong tất cả các lớp
        {
            for (auto &cl : Class)
            {
                listStudentOfClass(cl);
                cout << '\n';
            }
        }  
        // 5. Liệt kê danh sách sinh viên theo id của lớp
        void listStudentByIDofCLass (string id_class)
        {
            for (auto &cl : Class)
            {
                if (cl.getID() == id_class)
                {
                    cl.output();
                    cout << '\n';
                    return;
                }
            }
            cout << "Khong tim thay lop hoc co id nhu vay\n";
        }
        
        // 6. Liệt kê danh sách sinh viên có điểm lớn hơn hoặc bằng 5.0 và số lượng sinh viên 
        // Hàm in ra các sinh viên thỏa mãn điều kiện
        void list_with_constrain(bool check(), int &count)
        {
            for (auto &cl : Class)
            {
                for (auto &student : cl)
                {
                    if (check())
                    {
                        count++;
                        student.output();
                    }
                }
            }
        }
        bool check_greater_than_5(TLStudent &student)
        {
            return student.getNote() >= 5.0;
        }
        void list_greater_than_5()
        {
            int count = 0;
            list_with_constrain(check_greater_than_5(), count);
            cout << "So luong sinh vien co diem lon hon hoac bang 5.0: " << count << endl;
        }
        // 7. Liệt kê danh sách sinh viên có điểm dưới 5.0 và số lượng sinh viên
        bool check_less_than_5(TLStudent &student)
        {
            return student.getNote() < 5.0;
        }
        void list_greater_than_5()
        {
            int count = 0;
            list_with_constrain(check_less_than_5(), count);
            cout << "So luong sinh vien co diem nho hon 5.0: " << count << endl;
        }
        // 8. Liệt kê danh sách sinh viên có điểm cao nhất và số lượng sinh viên 
        bool check_has_max_note(TLStudent &student, double MAX)
        {
            return student.getNote == MAX;
        }
        void listStudentHaveMaxNote ()
        {
            double max_note = DBL_MIN;
            for (auto &cl : Class)
                max_note = max(max_note, *max_element(begin(cl), end(cl)));
            int count = 0;
            list_with_constrain(check_has_max_note(), count);
            cout << "So luong sinh vien co diem cao nhat: " << count << endl;
        }
};

int main()
{
    StudentManagement System;
    System.addStudent();
    System.listAllStudent();
}
