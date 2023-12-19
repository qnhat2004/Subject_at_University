#include <bits/stdc++.h>
using namespace std;

class Point
{
    double x, y;

    public:
        // Cấu tử - Constructor
        Point()
        {
           x = y = 0;
        }
    
        ~Point()
        {
            // Hàm hủy
        }
    
        friend istream &operator >> (istream &in, Point &p)
        {
            cout << "x, y = ";
            in >> p.x >> p.y;
            return in;
        }
    
        friend ostream &operator << (ostream &out, Point &p)
        {
            cout << "(" << p.x << ", " << p.y << ")";
            return out;
        }
    
        friend double KhoangCach (const Point &a, const Point &b)
        {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
        }
};

class Dagiac
{
    vector<Point> a;
    int Size;

    public:
        Dagiac(int Size)
        {
            this->Size = Size;
            a.resize(Size);
        }

        ~Dagiac()
        {
            // Hàm hủy
            a.clear();
        }

        // getter
        vector<Point> getVector() const {return a; }
        int getSize() const { return Size; }
        
        friend bool KiemTra(const Dagiac &d)
        {
            if (d.Size != 3) return false;
            double ab = KhoangCach(d.a[0], d.a[1]);
            double bc = KhoangCach(d.a[1], d.a[2]);
            double ca = KhoangCach(d.a[2], d.a[0]);
            return (ab + bc > ca && ab + ca > bc &&  bc + ca > ab);
        }

        friend bool KiemTraCan(const Dagiac &d)
        {
            if (!KiemTra(d)) return false;
            double ab = KhoangCach(d.a[0], d.a[1]);
            double bc = KhoangCach(d.a[1], d.a[2]);
            double ca = KhoangCach(d.a[2], d.a[0]);
            return (ab == bc || bc == ca || ca == ab);
        }
        
        friend ostream &operator << (const ostream &out, const Dagiac &dagiac);
        friend istream &operator >> (istream &in, Dagiac& dagiac);
};

ostream &operator << (ostream &out, const Dagiac &dagiac) 
{
    for (auto point : dagiac.getVector())
    {
        cout << point << ", ";
    }
    cout << "\n-----------------------------\n";
    return out;
}

istream &operator >> (istream &in, Dagiac& dagiac)
{
    for (int i = 0; i < dagiac.getSize(); ++i)
    {
        cin >> dagiac.a[i];
    }
    return in;
}

int main()
{
    int n;
    cout << "Nhap so luong da giac: "; cin >> n;

    vector<Dagiac> a;

    for (int i = 0; i < n; ++i)
    {
        int Size; 
        cout << "Nhap so dinh cua da giac thu " << i + 1 << ": "; cin >> Size;
        Dagiac dagiac(Size);
        cin >> dagiac;
        a.push_back(dagiac);
    }

    cout << "Cac da giac da nhap:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Cac diem thuoc da giac thu " << i + 1 << ": " << a[i] << endl;
    }
    
    cout << "Cac da giac thoa man la tam giac:\n";
    for (int i = 0; i < n; ++i)
    {
        if (KiemTra(a[i]))
        {
            cout << "Cac diem thuoc da giac thu " << i + 1 << ": " << a[i] << endl;
        }
    }        
    return 0;
}
