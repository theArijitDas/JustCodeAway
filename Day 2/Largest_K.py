t = int(input())
for _ in range(t):
    x, y = tuple(map(int, input().strip().split()))
    print(y//(x-1))