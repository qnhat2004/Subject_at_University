#### Downcasting và Upcasting là gì?
- **Downcasting**: chuyển từ lớp cha (base class) sang lớp con (derived class)
- **Upcasting**: chuyển từ lớp con sang lớp cha
#### Các loại type casting:
- **static_cast** là kiểu đơn giản nhất, nó là 1 compile-time cast, nghĩa là chuyển đổi trong thời gian biên dịch. Nó thực hiện những việc như chuyển đổi ngầm định giữa các kiểu (ví dụ: int, float,... và void*) và nó cũng có thể gọi hàm chuyển đổi tường minh (hoặc các hàm ẩn).
- Nên dùng static_cast với các kiểu dữ liệu nguyên thủy (int, float, ...)
```cpp
int a = 10;
void *p = static_cast<void*>(&a);
cout << *(static_cast<int*>(p)); // 10
```
- **dynamic_cast**: giúp thực hiện **downcasting** an toàn tại thời gian chạy (runtime). Để `dynamic_cast` hoạt động, lớp cơ sở phải chứa ít nhất 1 hàm ảo
- Dùng khi xử lý tính đa hình (Polymorphysm), sử dụng khi chuyển từ lớp cơ sở sang lớp dẫn xuất
- Kiểm tra tại thời gian chạy
```cpp
class Base {
  virtual ~Base() {}
};

class Derived : public Base {};

int main() {
  Base *baseptr = new Derived(); // Con trỏ kiểu Base trỏ đến vùng nhớ heap kiểu Derived

  Derived *d = dynamic_cast<Derived*>(baseptr); // Ép kiểu con trỏ baseptr thành Derived* sau đó gán cho con trỏ d

  if (d == nullptr) 
    cout << "Chuyen doi that bai\n";
  else
    cout << "Chuyen doi thanh cong\n";
}
```
