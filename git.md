# Các lệnh cơ bản về git

## git clone
tạo 1 bản sao của repositoty(kho lưu trữ) về local(cục bộ - máy cá nhân) của mình
```
git clone <link đuôi .git>
```

## git pull
lấy về những thay đổi mới nhất từ repository về local
``` 
git pull
```

## git add
Đánh dấu sự thay đổi của file/folder để chuẩn bị commit
```
git add <tên file/folder>
```

Thường thì ta cần đánh dấu thay đổi ở tất cả các file/folder, có thể sử dụng dấu . để đánh dấu tất cả
```
git add .
```

## git commit
Lưu lại những thay đổi đã đánh dấu bằng git add
```
git commit -m "nội dung commit"
```
