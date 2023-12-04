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
  
