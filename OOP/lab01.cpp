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
                Class[student.getClass().getName()].push_back(student);
            }
        }
        // 2. Xóa sinh viên khỏi danh sách
        void removeStudent(string id)
        {
            for (auto & cl : Class)
            {
                for (auto it = cl.second.begin(); it != cl.second.end(); ++it)
                {
                    if (it->getID() == id)
                    {
                        cl.second.erase(it);
                        return;
                    }
                }
            }
        }
        // 3. Tìm kiếm sinh viên theo mã
        void searchByID (string id)
        {
            bool check = false;
            for (auto & cl : Class)
            {
                for (auto &student : cl.second)
                {
                    if (student.getID() == id)
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
        void listStudentOfClass(string name_class)
        {
            for (auto &student : Class[name_class])
            {
                student.output();
            }
        }
        void listAllStudent () // Liệt kê tất cả sinh viên trong tất cả các lớp
        {
            for (auto &cl : Class)
            {
                listStudentOfClass(cl.first);
                cout << '\n';
            }
        }  
        // 5. Liệt kê danh sách sinh viên theo id của lớp
        void listStudentByIDofCLass (string id_class)
        {
            for (auto &cl : Class) // Duyêt qua các tên lớp
            {
                for (auto &student : cl.second)
                {
                    if (student.getClass().getID() == id_class)
                    {
                        student.output();
                    }
                }
            }
            cout << "Khong tim thay lop hoc co id nhu vay\n";
        }
        
        // 6. Liệt kê danh sách sinh viên có điểm lớn hơn hoặc bằng 5.0 và số lượng sinh viên 
        bool check_greater_than_5(TLStudent &student)
        {
            return student.getNote() >= 5.0;
        }
        void list_greater_than_5()
        {
            int count = 0;
            for (auto &cl : Class)
            {
                for (auto &student : cl.second)
                {
                    if (check_greater_than_5(student))
                    {
                        count++;
                        student.output();
                    }
                }
            }
            cout << "So luong sinh vien co diem lon hon hoac bang 5.0: " << count << endl;
        }
        // 7. Liệt kê danh sách sinh viên có điểm dưới 5.0 và số lượng sinh viên
        bool check_less_than_5(TLStudent &student)
        {
            return student.getNote() < 5.0;
        }
        void list_less_than_5()
        {
            int count = 0;
            for (auto &cl : Class)
            {
                for (auto &student : cl.second)
                {
                    if (check_less_than_5(student))
                    {
                        count++;
                        student.output();
                    }
                }
            }
            cout << "So luong sinh vien co diem nho hon 5.0: " << count << endl;
        }
        // 8. Liệt kê danh sách sinh viên có điểm cao nhất và số lượng sinh viên 
        bool check_has_max_note(TLStudent &student, double MAX)
        {
            return student.getNote() == MAX;
        }
        void listStudentHaveMaxNote ()
        {
            double max_note = 0;
            for (auto &cl : Class)
                max_note = std::max(max_note, max_element(begin(cl.second), end(cl.second), [](TLStudent &a, TLStudent &b) {return a.getNote() < b.getNote();})->getNote());
            int count = 0;
            for (auto &cl : Class)
            {
                for (auto &student : cl.second)
                {
                    if (check_has_max_note(student, max_note))
                    {
                        count++;
                        student.output();
                    }
                }
            }
            cout << "So luong sinh vien co diem cao nhat: " << count << endl;
        }
};

int main()
{
    StudentManagement System;
    System.addStudent();
    System.listAllStudent();
}
