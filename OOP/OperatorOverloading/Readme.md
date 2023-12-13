**TÁC DỤNG CỦA NẠP CHỒNG**
- nạp chồng phương thức giúp tái sử dụng phương thức đó cho các kiểu dữ liệu khác nhau, hoặc với số lượng tham số khác nhau
  
**NẠP CHỒNG TOÁN TỬ**

**Lý do phải nạp chồng toán tử**: các toán tử thông thường được sử dụng với các kiểu dữ liệu nguyên thủy được định nghĩa sẵn (int, double, float,...) nhưng ta muốn sử dụng toán tử giữa các kiểu dữ liệu tự định nghĩa (class, struct) thì ta phải định nghĩa thêm cho toán tử ấy. Nạp chồng không làm mất đi ý nghĩa ban đầu của toán tử mà bổ sung thêm ý nghĩa mới với những ý nghĩa ban đầu.

* Cú pháp nạp chồng toán tử:
**<kiểu trả về> operator <danh sách đối số>**

**Các cách sử dụng nạp chồng toán tử:**
- Khai báo nó trong **class**
- Sử dụng **Friend function**
- Nếu dùng hàm trả về như bình thường: dùng **setter, getter**
- Khai báo các thuộc tính về **Public**

**Các hàm nạp chồng:**
- Nạp chồng toán tử **cộng, trừ, nhân, chia** giữa 2 đối tượng
- Nạp chồng toán tử **dấu ngoặc đơn**: tạo 1 functional object để so sánh 2 đối tượng trong **hàng đợi ưu tiên**
- Nạp chồng toán tử **tăng giảm: Increment & Decrement**: tăng hoặc giảm 1 giá trị của đối tượng được nạp chồng
    - **Lý do prefix không có dummy parameter mà postfix lại có:**
          - Dùng nó để phân biệt giữa **prefix** và **postfix**
          - Tham số giả này được tạo ra với giá trị = 0, lúc ấy nó giống như biểu thức trung tố (+, -, >, <) giữa 2 toán hạng với 1 giá trị bằng 0
    - **Phân biệt sự khác nhau của prefix và postfix:**
          - **prefix**: tăng trực tiếp giá trị của đối tượng, trả về đối tượng đó -> giá trị trả về đã được tăng rồi
          - **postfix**: tạo 1 bản sao của đối tượng, tăng giá trị của đối tượng đó, trả về giá trị của bản sao (giá trị cũ) -> đối tượng đã được tăng nhưng giá trị trả về vẫn là giá trị cũ, nghĩa là sau khi hết              câu lệnh ta mới nhìn thấy giá trị thật(đã được tăng) của đối tượng
  
