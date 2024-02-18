from functools import reduce
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    f = lambda a, b: (a//b + 1) * b
    print(reduce(f, arr))