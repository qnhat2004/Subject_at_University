#include <bits/stdc++.h>
using namespace std;

/* Conversion Operator - toán tử chuyển đổi: đôi khi, cần phải chuyển đổi 1 loại dữ liệu này sang loại dữ liệu khác 1 cách ngầm định
    -> Cần đến toán tử chuyển đổi
*/

class Complex // Số phức: số có dạng a + bi, trong đó a = real là phần thực, bi = imaginary là phần ảo
{
    double real;
    double imag;

    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

        // magnitude - độ lớn, usual function style (kiểu hàm thông thường)
        double mag() { return getMag(); }

        // magnitude: conversion operator
        operator double()
        {
            cout << "Conversion operator called\n";
            return getMag();
        }

    private:
        double getMag() // Độ lớn của số phức: |z| = sqrt(a^2 + b^2)
        {
            return sqrt(real * real + imag * imag);
        }
};

int main()
{
    // a complex object
    Complex com(3.0, 4.0);

    // print magnitude
    cout << com.mag() << endl;

    // use conversion operator to convert Complex to double
    // Toán tử chuyển đổi được gọi trước khi so sánh với 1 số kiểu double hoặc khi in đối tượng ra màn hình
    cout << com << endl;
}
