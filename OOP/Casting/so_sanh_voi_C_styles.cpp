#include <bits/stdc++.h>
using namespace std;

// Implicit type conversion - Ép kiểu ngầm định: trình biên dịch tự động chuyển đổi từ kiểu dữ liệu này sang kiểu dữ liệu khác (kiểu dữ liệu cơ sở) - kiểu dữ liệu nguyên thủy
// Emplicit type conversion - Ép kiểu tường minh: lập trình viên sử dụng toán tử ép kiểu (casting operation) để thực hiện việc chuyển đổi
    // - Có 2 cách ép kiểu tường minh phổ biến:
        // + C-style casts: (type)expression
        // + Static casts: static_cast<type_id>(expression)

void Implicit()
{
    double b = 3 / 2; // 1 -> chuyển đổi ngầm định thành 1.0 -> gán cho b
    cout << b << endl; // 1

    b = 3.0 / 2; // double / int -> double / double -> double -> gán cho b. Trình biên dịch tự động chuyển đổi các toán hạng sang kiểu dữ liệu có độ ưu tiên cao hơn
    cout << b << endl; // 1.5

    // với trường hợp toán hạng là biến -> sử dụng ép kiểu tường minh để trình biên dịch hiểu ý đồ của lập trình viên
    /* Ép kiểu tường minh (Emplicit type conversion) là quá trình chuyển đổi dữ liệu 1 cách tường minh do lập trình viên, sử dụng toán tử ép kiểu (casting operator) */
    int a = 6, c = 4;
    b = a / c;
    cout << b << endl; // 1
}

// Chú ý: Ép kiểu tường minh C-style casts không được trình biên dịch complier kiểm tra tại thời điểm biên dịch, nên trình biên dịch sẽ không đưa ra các cảnh báo trong trường hợp chuyển đổi không đúng
// Chú ý: Tránh sử dụng ép kiểu tường minh C-style.
void C_style_Casts()
{
    // Sử dụng thông qua toán tử () và tên kiểu dữ liệu cần chuyền
    int n1 = 3;
    int n2 = 2;
    double d = (double) n1 / n2;
    cout << d << endl;
}

/*
    - Ưu điểm:
        + Yêu cầu complier kiểm tra kiểu dữ liệu tại thời điểm biên dịch chương trình, hạn chế những lỗi không mong muốn
    - Chú ý:
        + Nên sử dụng toán tử static_cast thay vì C-style 
*/
void Static_Casts()
{
    int n = 75;
    // cout << static_cast<char>(n) << endl; // in ký tự với mã ASCII là 75 - chữ K

    char ch = 'K';
    // cout << static_cast<int>(ch) << endl; // In mã ASCII của chữ K - 75

    int n1 = 3;
    int n2 = 2;
    double d = static_cast<double>(n1) / n2;
    // cout << d << endl;

    char c = 'a';
    n1 = 10;

    int *q = (int*)&n1; // Tương đương với int *q = &n1; ép kiểu địa chỉ của n1 thành int*, nghĩa là ép kiểu địa chỉ của n1 thành con trỏ kiểu int
    // - việc ép kiểu địa chỉ thành con trỏ giúp truy cập các phần tử trong 1 container hoặc một đối tượng dữ liệu phức tạp. Khi đó ta có thể ép kiểu
    //      địa chỉ thành con trỏ để truy cập các phần tử trong đối tượng dữ liệu
    /*
        VD: int arr[n] // Mảng có kích thước n
            int *ptr = (int*)&arr // Ép kiểu địa chỉ của mảng thành con trỏ kiểu int*
            int i = 0;
            ptr[i] = 10; // Gán giá trị 10 cho phần tử thứ i trong mảng
    */

    // int *p = static_cast<int*>(&c); // Ép kiểu địa chỉ của c thành con trỏ kiểu int*, static_cast sẽ báo lỗi vì không thể ép kiểu địa chỉ kiểu char thành con trỏ kiểu int
    // int *p = (int*)&c; // C-style không báo lỗi, nhưng sẽ báo lỗi khi chạy
}

int main()
{
    Static_Casts();
    return 0;
}
