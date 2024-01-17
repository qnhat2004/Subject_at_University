# Nạp chồng trong hướng đối tượng
## TÁC DỤNG CỦA NẠP CHỒNG
- nạp chồng phương thức giúp tái sử dụng phương thức đó cho các kiểu dữ liệu khác nhau, hoặc với số lượng tham số khác nhau
  
## NẠP CHỒNG TOÁN TỬ

**Lý do phải nạp chồng toán tử**: các toán tử thông thường được sử dụng với các kiểu dữ liệu nguyên thủy được định nghĩa sẵn (int, double, float,...) nhưng ta muốn sử dụng toán tử giữa các kiểu dữ liệu tự định nghĩa (class, struct) thì ta phải định nghĩa thêm cho toán tử ấy. Nạp chồng không làm mất đi ý nghĩa ban đầu của toán tử mà bổ sung thêm ý nghĩa mới với những ý nghĩa ban đầu.

## Cú pháp nạp chồng toán tử:
```cpp 
<kiểu trả về> operator <danh sách đối số> { }
```

## Các hàm nạp chồng:
- toán tử **cộng, trừ, nhân, chia**: [here](https://github.com/qnhat2004/Subject_at_University/blob/main/OOP/OperatorOverloading/CongTruNhanChia.cpp)
- toán tử **dấu ngoặc đơn**: **Functor**(function object) - có thể sử dụng đối tượng như 1 hàm: [Here](https://github.com/qnhat2004/Subject_at_University/blob/main/OOP/OperatorOverloading/DauNgoacDon.cpp)
- toán tử **tăng & giảm: Increment & Decrement**: tăng hoặc giảm 1 giá trị của đối tượng được nạp chồng. [Here](https://github.com/qnhat2004/Subject_at_University/blob/main/OOP/OperatorOverloading/TangGiam.cpp)
    
  
