# DFS Algorithm
def dfs(graph, start_node, end_node):
    visited = [start_node]
    stack = [start_node]
    parent = {start_node: None}

    while stack:
        current_node = stack.pop()
        if current_node == end_node:
            path = []
            while parent[current_node] != None:
                path.append(current_node)
                current_node = parent[current_node]
            path.append(start_node)
            print("path:", *path[::-1])
            return
        
        for adjacent_node in graph[current_node]:
            if adjacent_node not in visited:
                visited.append(adjacent_node)
                stack.append(adjacent_node)
                parent[adjacent_node] = current_node
    
    print("No path found")

print("DFS Algorithm")
n, m = map(int, input("Enter number of vertices and edges: ").split())
print("Enter the edges list:")

graph = {} # Adjacency list
for _ in range(m):
    u, v = input().split()
    if u not in graph:
        graph[u] = []
    graph[u].append(v)
    # Undirected graph
    # if v not in graph:
    #     graph[v] = []      
    # graph[v].append(u)

start_node, end_node = input("Enter start and end node: ").split()

dfs(graph, start_node, end_node)