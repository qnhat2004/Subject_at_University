# Cấu trúc dữ liệu hàng đợi ưu tiên (Priority_queue in C++)
- Nó triển khai ctdl **Heap**
- Sử dụng mảng hoặc vector làm container
- Phần tử đầu tiên (khi được lấy ra) từ hàng đợi (nhưng nó là phần tử cuối cùng của mảng) là phần tử có độ ưu tiên cao nhất (nó lớn nhất hoặc nhỏ nhất trong mảng)
- Mỗi phần tử trong hàng đợi ưu tiên có mức ưu tiên cố định
- Các phương thức: **empty, size, top, push, top**: Độ phức tạp thời gian **O(1)**, không gian phụ trợ **O(1)**
- Phương thức **swap**: hoán đổi 2 hàng đợi ưu tiên, độ phức tạp thời gian: **O(1)**, không gian phụ trợ **O(N)**
- Phương thức **emplace**: thêm 1 đối tượng mới vào đầu hàng đợi, độ phức tạp thời gian **O(log(N))**, không gian phụ trợ **O(1)**
- **Push** tạo 1 bản sao của đối tượng sau đó thêm nó vào container, **Emplace** xây dựng 1 đối tượng mới tại vị trí đầu hàng đợi từ các tham số được cung cấp
