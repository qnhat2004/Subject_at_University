from collections import deque

# BFS Algorithm
def BFS_using_List(adj, start_node, end_node): # Không tối ưu vì pop(0) của list là O(n)
    visited = [start_node]
    queue = [start_node]
    parent = {start_node: None}

    while queue:
        cur_node = queue.pop(0)
        if cur_node == end_node:
            return parent        
        for neighbor in adj[cur_node]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)
                parent[neighbor] = cur_node    
    return None

def BFS_using_Deque(adj, start_node, end_node): # Tối ưu hơn vì popleft() của deque là O(1) và tìm kiếm trong set là O(1) (bảng băm - hashtable)
    visited = set([start_node])
    queue = deque(start_node)
    parent = {start_node: None}

    while queue:
        cur_node = queue.popleft()
        if start_node not in adj:
            raise KeyError(start_node) # ném ra ngoại lệ KeyError
        if end_node not in adj:
            raise KeyError(end_node)
        if cur_node == end_node:
            return parent
        for neighbor in adj[cur_node]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)
                parent[neighbor] = cur_node
    return None

def show_path(parent, start_node, end_node):
    path = []
    cur = end_node
    while cur is not None:
        path.append(cur)
        cur = parent[cur]
    print(*path[::-1])

# Driver code
if __name__ == "__main__":
    adj = {
        "A": ["B", "C"],
        "B": ["A", "D", "E"],
        "C": ["A", "F"],
        "D": ["B"],
        "E": ["B", "F"],
        "F": ["C", "E"]
    }
    start_node = "A"
    end_node = "G"

    try:
        # parent = BFS_using_List(adj, start_node, end_node)
        parent = BFS_using_Deque(adj, start_node, end_node)
        show_path(parent, start_node, end_node)
    except KeyError as e: # Đối tượng ngoại lệ được gán vào biến e
        print(f"Error: Node {e} is not in graph")
    except Exception as e: # Nếu ngoại lệ không phải KeyError, nó vẫn được gán vào biến e sau đó in ra lỗi tổng quát
        print("Exception:", e)
    else:
        print(f"No path from {start_node} to {end_node}")
