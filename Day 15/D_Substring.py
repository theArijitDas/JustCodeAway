from collections import deque

n, m = tuple(map(int, input().strip().split()))
s = input()
graph = {i:[] for i in range(n)}
ans = None
inDegree = [0]*n
for _ in range(m):
    x, y = tuple(map(int, input().strip().split()))
    inDegree[y-1]+=1
    if x==y:
        ans = -1
        break
    graph[x-1].append(y-1)

def has_cycle(graph: dict) -> bool:
    rec_stk = set()
    visited = set()
    
    def dfs(node: int) -> bool:
        if node in rec_stk:
            return True
        if node in visited:
            return False
        
        rec_stk.add(node)
        visited.add(node)
        
        for neighbour in graph.get(node, []):
            if dfs(neighbour):
                return True
        
        rec_stk.remove(node)
        return False
    
    for node in graph:
        if dfs(node):
            return True
    return False

if has_cycle(graph):
    ans = -1

if ans is None:
    letters = [[0]*26 for _ in range(n)]
    nodes = [node for node in range(n) if inDegree[node]==0]
    queue = deque(nodes)
    
    ans = 0
    while queue:
        node = queue.pop()
        letters[node][ord(s[node])-ord('a')] += 1
        
        ans = max(ans, max(letters[node]))
        
        for neighbour in graph[node]:
            for i in range(26):
                letters[neighbour][i] = max(letters[neighbour][i], letters[node][i])
            inDegree[neighbour]-=1
            if inDegree[neighbour] == 0:
                queue.append(neighbour)
    print(ans)
else:
    print(ans)