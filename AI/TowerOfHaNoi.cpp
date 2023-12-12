#include <bits/stdc++.h>
using namespace std;

// Tháp Hà Nội sử dụng Breadth First Search
typedef vector<int> state; // state = {a, b, c} lần lượt là vị trí hiện tại của đĩa lớn nhất đến đĩa nhỏ nhất, vd {1, 2, 3} tức là đĩa to nhất ở cột 1,...

void towerOfHaNoi(int n, char from_rod, char to_rod, char aux_rod) // aux_rod: auxiliary rod - cột trung gian
{
    if (n == 0) return;

    towerOfHaNoi(n-1, from_rod, aux_rod, to_rod); // chuyển n-1 đĩa từ cột 1 sang cột 2, cột 3 là cột trung gian
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl; // Di chuyển đĩa n từ cột from_rod sang cột to_rod
    towerOfHaNoi(n-1, aux_rod, to_rod, from_rod); // chuyển n-1 đĩa từ cột 2 sang cột 3, cột 1 là cột trung gian
}

int main()
{
    int N = 3;
    towerOfHaNoi(N, 'A', 'C', 'B');
    return 0;
}
