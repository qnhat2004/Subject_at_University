#include <bits/stdc++.h>
using namespace std;

// Unary Arithmetic - toán t? s? h?c 1 ngôi
// ++, --

class Obj
{
    int x, y;

    public:
        Obj() : x(0), y(0) {} // default constructor
        Obj(int x, int y) : x(x), y(y) {} // constructor with parameters, gán giá tr? x, y cho d?i tu?ng

        friend istream& operator >> (istream& in, Obj &a)
        {
            in >> a.x >> a.y;
            return in;
        }
        friend ostream& operator << (ostream& out, Obj &a)
        {
            out << a.x << " " << a.y << endl;
            return out;
        }

        Obj& operator++() // prefix increment, toán t? & du?c s? d?ng d? thay d?i tr?c ti?p giá tr? c?a d?i tu?ng
        {
            ++this->x;
            ++this->y;
            return *this;
        }

        Obj operator++(int) // postfix increment, dummy parameter int - tham s? gi?, giá tr? m?c d?nh b?ng 0, dùng d? phân bi?t v?i prefix
        {
            Obj temp(*this); // copy constructor, t?o 1 d?i tu?ng b?n sao c?a d?i tu?ng hi?n t?i
            operator++(); // g?i hàm prefix increment
            return temp; // tr? v? giá tr? tru?c khi tang
        }

        Obj& operator--() // prefix decrement
        {
        	--x;
        	--y;
        	return *this;
		}
		
		Obj operator--(int) // postfix decrement
		{
			Obj temp(*this);
			operator--(); // prefix decrement
			return temp;
		}
};

int main()
{
    Obj a(5, 6);
    // cin >> a;
    
    Obj b = a++; // postfix increment
    cout << "a++ = " << b; // prefix increment
    cout << "a = " << a; 
    cout << "++a = " << ++a; // postfix increment
    
    cout << endl;
    
    b = a--;
    cout << "a-- = " << b; // prefix decrement
    cout << "a = " << a; 
    cout << "--a = " << --a; // postfix decrement
    
    return 0;
}
