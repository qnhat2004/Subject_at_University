'''
* Hạn chế của thuật toán tìm kiếm sâu giới hạn (hay còn gọi là thuật toán tìm kiếm sâu dần, DLS):
- Tăng dần độ sâu rồi thực hiện DLS(0), DLS(1), ... , DLS(Limited)
- Nếu nút cần tìm nằm ở độ sâu lớn hơn độ sâu giới hạn -> không tìm được
-> Cải tiến bằng thuật toán tìm kiếm sâu dần (Depth Deepening Search - DDS)
* Nhược điểm của thuật:
- Mỗi lần tăng độ sâu sẽ thực hiện DLS lại 1 lần -> tốn thời gian
- Có thể không tìm thấy nghiệm nếu nằm sâu hơn độ sâu tối đa
'''
from Depth_Limited_Search import Graph

def Depth_Deepening_Search(graph, start, goal, limited):
    for depth in range(limited + 1):
        if graph.Depth_Limited_Search(start, goal, depth):
            return True
    return False

if __name__ == "__main__":
    g = Graph()
    start, goal, limited = g.Input()
    if Depth_Deepening_Search(start, goal, limited):
        print("\nTìm thấy đường đi")
        g.show_path(g.parent, start, goal)
    else:
        print("\nKhông tìm thấy đường đi")
