#include <bits/stdc++.h>
using namespace std;

class Point
{
    double x, y;

    // Cấu tử - Constructor
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
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
        cout << "(" << p.x << ", " << p.y << ")" << endl;
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
};

int main()
{
    int n;
    cout << "Nhap so luong da giac: "; cin >> n;

    vector<Dagiac> a(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "toa do diem thu " << i + 1 << ": ";
    }

    for (int i = 0; i < n; ++i)
    {
        if (KiemTra(a[i]))
        {
            cout << a[i];
        }
    }        
    return 0;
}
