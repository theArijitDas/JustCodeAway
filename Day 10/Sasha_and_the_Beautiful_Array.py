t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    print(max(a)-min(a))