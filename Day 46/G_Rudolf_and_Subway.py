from io import open
from collections import deque
from functools import reduce
import sys
output = sys.stdout.write

I = iter(open(0))
T = int(next(I))
# ANS = [None for _ in range(T)]

for t in range(T):
    n, m = map(int, next(I).strip().split())
    
    parents = [set() for _ in range(n+1)]
    for _ in range(m):
        u, v, c = map(int, next(I).strip().split())
        parents[u].add(c)
        parents[v].add(c)
    
    graph = {i : deque() for i in range(1, n+1)}
    for p in set().union(*parents):
        graph[str(p)] = deque()
    
    for i in range(1, n+1):
        for p in parents[i]:
            graph[i].append(str(p))
            graph[str(p)].append(i)
    
    del parents
    
    s, d = map(int, next(I).strip().split())
    
    q = deque()
    q.append(s)
    distance = {node : float("inf") for node in graph}
    distance[s] = 0
    while q:
        u = q.popleft()
        if u == d: break
        for v in graph[u]:
            if distance[v] == float("inf"):
                distance[v] = 1 + distance[u]
                q.append(v)
    
    output(str(distance[d]//2)+"\n")    