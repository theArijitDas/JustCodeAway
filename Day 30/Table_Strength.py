t = int(input())
for _ in range(t):
    n = int(input())
    heights = sorted(list(map(int, input().strip().split())))
    ans = heights[-1]
    for i in range(2, n + 1):
        ans = max(ans, i * heights[-i])
    print(ans)