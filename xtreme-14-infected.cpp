from collections import defaultdict, deque

def bfs(graph, start, target):
    visited = set([start])
    queue = deque([start])
    path = {start: None}
    
    while queue:
        node = queue.popleft()
        if node == target:
            break
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                path[neighbor] = node
                queue.append(neighbor)
    
    infected_chain = []
    if target in visited:
        node = target
        while node is not None:
            infected_chain.append(node)
            node = path[node]
    
    return infected_chain

def solve():
    inputs = [
        "6 5",
        "1 2",
        "1 3",
        "2 4",
        "3 4",
        "4 5",
        "2",
        "1 5",
        "4 3"
    ]
    
    input_idx = 0
    
    def custom_input():
        nonlocal input_idx
        result = inputs[input_idx]
        input_idx += 1
        return result
    
    N, M = map(int, custom_input().split())
    
    graph = defaultdict(list)
    
    for _ in range(M):
        A, B = map(int, custom_input().split())
        graph[A].append(B)
        graph[B].append(A)
    
    Q = int(custom_input())
    
    for _ in range(Q):
        F, S = map(int, custom_input().split())
        
        infected_chain = bfs(graph, F, S)
        
        if len(infected_chain) > 2:
            print(len(infected_chain) - 1)
        else:
            print(1 if len(infected_chain) == 2 else 0)

solve()
