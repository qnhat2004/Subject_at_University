#include <bits/stdc++.h>
using namespace std;

#define show(a) for(auto &i : a) cout << i << ' ';

// Functor - Function Object, Nó có thể sử dụng đối tượng như 1 hàm
// Functor được sử dụng phổ biến nhất cùng với STL
// Nó có thể được sử dụng như 1 hàm chỉ có 1 tham số nhưng thực chất nó thao tác với nhiều tham số

struct add_x
{
    int x;
    public:
        add_x(int x) : x(x) {} // Constructor
        int operator()(int y) const { return x + y; }
};

// Ưu điểm thực sự của functor là nó có thể lưu trữ trạng thái
class Mathcher
{
    int target;
    public:
        Mathcher(int m) : target(m) {}
        bool operator()(int x) const { return x == target; }
};

int main()
{
    // create an instance of the functor class
    add_x add34(34); // Tạo 1 đôi tượng add34 có add34.x = 34
    int i = add34(6); 
    // assert(i == 41); // Assertion failed: i == 41, file implementation2.cpp, line 18
    assert(i == 40); // Assertion passed

    vector<int> in = {1, 2, 3};
    vector<int> out(in.size());

    transform(in.begin(), in.end(), out.begin(), add_x(1)); // std::transform yêu cầu hàm 1 ngồi (unary function) nên không thể truyền 1 hàm bình thường được
    show(out); // 2 3 4

    Mathcher is5(5); // target = 5
    assert(is5(5)); // Same as: if (5 == target)

    return 0;
}
