n, m = tuple(map(int, input().strip().split()))
adjList = {i:[] for i in range(n)}
for _ in range(m):
    x, y = tuple(map(int, input().strip().split()))
    x, y = x-1, y-1
    adjList[x].append(y)
    adjList[y].append(x)

visited = set()
ans = []

def dfs(curr):
    stack = [curr]
    while stack:
        curr = stack.pop()
        visited.add(curr)
        for e in adjList[curr]:
            if e not in visited:
                stack.append(e)

def bfs(curr):
    queue = [curr]
    while queue:
        curr = queue.pop(0)
        visited.add(curr)
        for e in adjList[curr]:
            if e not in visited:
                queue.append(e)

for curr in range(n):
    if curr not in visited:
        dfs(curr)
        # bfs(curr)
        ans.append(curr)

print(len(ans)-1)
prev = ans[0]
for city in ans[1:]:
    print(prev+1, city+1)
    prev = city