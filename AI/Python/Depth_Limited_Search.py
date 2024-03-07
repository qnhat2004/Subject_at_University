''' 
Depth Limited Search - Tìm kiếm sâu lặp
* Hạn chế của DFS:
- Lặp trạng thái -> giải pháp: boolean visited
- Sâu vô hạn -> giải pháp: tìm kiếm theo chiều sâu hạn chế
* Hạn chế của DLS:
- Nút nằm ở độ sâu hơn không được khám phá -> không tìm được đỉnh đích
'''

from collections import defaultdict

class Graph:
    # Constructor
    def __init__(self):
        self.adj = defaultdict(list)
        self.parent = defaultdict()
    def addEdge(self, u, v):
        self.adj[u].append(v)

    def show_path(self, parent, start, goal):
        path = []
        while parent[goal] != None:
            path.append(goal)
            goal = parent[goal]
        print(*path[::-1])
    
    def Depth_Limited_Search(self, start, goal, limited):
        visited = set()
        visited.add(start)
        
        self.parent[start] = None

        stack = [start]
        h = 0 # độ sâu hiện tại

        while stack:
            cur = stack.pop()
            if cur == goal:
                return True
            if h == limited:
                continue
            for u in self.adj[cur]:
                if u not in visited:
                    stack.append(u)
                    visited.add(u)
                    h += 1
                    self.parent[u] = cur            
        return False

    def Input(self): # Nếu không có self -> phương thức tĩnh
        n, m = map(int, input("Nhập số đỉnh và số cạnh: ").split())
        for i in range(m):
            u, v = input(f"Nhập cạnh thứ {i+1}: ").split()
            g.addEdge(u, v)
        start, end = input("Nhập đỉnh bắt đầu và đỉnh đích: ").split()
        limited = int(input("Nhập độ sâu giới hạn: "))
        return start, end, limited
        
if __name__ == "__main__":
    g = Graph()
    start, end, limited = g.Input()
    if g.Depth_Limited_Search(start, end, limited):
        print("\nTìm thấy đường đi")
        g.show_path(g.parent, start, end)
    else:
        print("\nKhông tìm thấy đường đi")
