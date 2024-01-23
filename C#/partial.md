# Từ khóa partial
Trong C#, từ khóa **parital** được sử dụng để phân chia định nghĩa của 1 lớp, giao diện, struct hoặc method ra thành nhiều file mã nguồn khác nhau. Khi biên dịch, trình biên dịch sẽ tự động hợp nhất các file mã nguồn này lại.

Điều này hữu ích trong các trường hợp:
- Dự án lớn, những lớp mà mã nguồn dài cần chia thành nhiều file
- Khi làm việc với các IDE, nó có thể phát sinh code 1 cách tự động