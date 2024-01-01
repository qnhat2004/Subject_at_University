# 🤖 AI - Trí tuệ nhân tạo
## Các thuật toán tìm kiếm
  ### Tìm kiếm mù: không có thông tin đánh giá (quá khứ, tương lai) của các trạng thái, kết thúc thuật toán khi tìm kiếm thành công hoặc duyệt hết tất cả trạng thái
  - Tìm kiếm theo chiều rộng - [Breath First Search(BFS)](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/BFS_queue.cpp)
  - Tìm kiếm theo chiều sâu - [Depth First Search(DFS)](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/DFS_Stack.cpp)
  - Tìm kiếm theo chiều sâu hạn chế - [Depth Limited Search(DLS)](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/Depth_Limited_Search.cpp): chọn chiều sâu giới hạn và kết thúc tìm kiếm khi tìm kiếm thành công hoặc đạt giới hạn độ sâu
  - Tìm kiếm sâu lặp - [Depth Deepening Search (DPS)](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/Depth_Deepening_Search.cpp): lặp lần lượt các độ sâu tăng dần từ 0 đến limited_h
   ### Tìm kiếm với tri thức bổ sung: là những thuật toán tìm kiếm có thông tin hướng dẫn
   #### - Tìm kiếm kinh nghiệm: Thông tin tương lai, dựa vào hàm đánh giá Heuristic
   - Tìm kiếm tốt nhất đầu tiên - [Best First Search](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/Best_first_search.cpp): Sắp xếp tăng hoặc giảm dần hàng chờ **Open** dựa theo hàm đánh giá **Heuristic**, sử dụng tìm kiếm theo chiều rộng kết hợp CTDL hàng đợi (hàng đợi ưu tiên) 
   - Tìm kiếm leo đồi - [Hill Climbing Search](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/Hill_climbing_search.cpp): Khác với tìm kiếm tốt nhất đầu tiên, tìm kiếm leo đồi sắp xếp các trạng thái tiếp theo dựa theo hàm đánh giá Heuristic sau đó với thêm vào ngăn xếp (Stack). Nó sử dụng thuật toán tìm kiếm theo chiều sâu kết hợp hàm đánh giá h(u).
   - Tìm kiếm Beam - [Beam Search](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/Beam_Search.cpp): Giống tìm kiếm tốt nhất đầu tiên nhưng chỉ phát triển k đỉnh tốt nhất tại mỗi độ sâu
   #### - Tìm kiếm tối ưu - Dựa vào hàm f(u) = h(u) + g(u)
   - Các kỹ thuật tìm đường đi ngắn nhất:
       - A-Star (A*)
       - Nhánh cận (Branch And Bound)
   - Các kỹ thuật tìm kiếm cục bộ:
       - Tìm kiếm leo đồi - Hill CLimbing
   #### - Tìm kiếm có đối thủ
   - Thuật toán Min-max(Mini-max)
   - Cắt tỉa Alpha-Beta

<br/>

![image](https://github.com/qnhat2004/Subject_at_University/assets/126136518/34b6e7c5-89cc-41e3-b321-4897bbf02261)


## Sử dụng thuật toán tìm kiếm vào tìm đường đi trong các trò chơi
  - Bài toán tháp Hà Nội ([Tower of Ha Noi](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/TowerOfHaNoi.cpp))
  - Đong nước(có 3 bình dung tích lần lượt là a,b,c lượng nước hiện tại trong bình lần lượt là x,y,z; tìm cách đạt m lít nước trong bình thứ nhất) [DongNuoc.cpp](https://github.com/qnhat2004/Subject_at_University/blob/main/AI/DongNuoc.cpp)
> [!NOTE]
> Các thuật toán tìm kiếm đều được phát triển từ 2 thuật toán DFS và BFS.

> [!WARNING]
> Một số thuật toán có thể bị cài đặt lỗi hoặc chạy cho ra output không chính xác.
