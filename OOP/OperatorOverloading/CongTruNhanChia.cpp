#include <bits/stdc++.h>
using namespace std;

// Binary Arithmetics - Số học nhị phân

class Complex
{
    int real, img; // img = imaginary (ảo)

    public:
        Complex(int real = 0, int img = 0)
        {
            this->real = real;
            this->img = img;
        }

        // Operator overloading, nó tự động được gọi khi '+' được sử dụng giữa 2 đối tượng Complex
        // Nó sẽ trả về 1 đối tượng mới, nên ta cần phải khỏi tạo 1 đối tượng mới
        Complex operator + (const Complex &obj)
        {
            Complex res;
            res.real = this->real + obj.real;
            res.img = this->img + obj.img;
            return res;
        }

        void print() { cout << "real = " << real << ", imaginary = " << img << endl; }

        // Cách 2: Không cần khởi tạo đối tượng mới, chỉ cần trả về 1 đối tượng thôi
        Complex operator - (const Complex &obj)
        {
            return Complex(this->real - obj.real, this->img - obj.img);
        }

        friend Complex operator * (const Complex &obj1, const Complex &obj2);
};

Complex operator * (const Complex &obj1, const Complex &obj2)
{
    return Complex(obj1.real * obj2.real, obj1.img * obj2.img); 
}

int main()
{
    Complex c1(10, 5), c2(2, 4);

    Complex c3 = c1 + c2; // c1.operator+(c2), '+' được gọi như 1 hàm 
    c3.print();

    c3 = c1 - c2; // c1.operator-(c2)
    c3.print();

    c3 = c1 * c2; // c1.operator*(c2)
    c3.print();
}
