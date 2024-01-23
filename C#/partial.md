# Từ khóa partial
Trong C#, từ khóa **parital** được sử dụng để phân chia định nghĩa của 1 lớp, giao diện, struct hoặc method ra thành nhiều file mã nguồn khác nhau. Khi biên dịch, trình biên dịch sẽ tự động hợp nhất các file mã nguồn này lại.

Điều này hữu ích trong các trường hợp:
- Dự án lớn, những lớp mà mã nguồn dài cần chia thành nhiều file
- Khi làm việc với các IDE, nó có thể phát sinh code 1 cách tự động

Giả sử ta có thể tạo 1 lớp **Product** với 2 file mã nguồn **Product1.cs** và **Product2.cs** như sau:
```cs
// Product1.cs
public partial class Product
{
    public string Name { get; set; }
    public bool Order(int number = 0) {
        return true;
    }
}

// Product2.cs
public partial class Product
{
    public int numberBrought() {
        return 100;
    }   
}
```