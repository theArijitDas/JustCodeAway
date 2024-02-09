t = int(input())
for _ in range(t):
    n = int(input())
    buildings = list(map(int, input().strip().split()))
    if n&1:
        ans = 0
        for i in range(1, n, 2):
            ans += max(0, max(buildings[i-1], buildings[i+1]) - buildings[i] + 1)
    else:
        prefix, suffix = [0]*n, [0]*n
        for i in range(2, n, 2):
            prefix[i] = prefix[i-2] + max(0, max(buildings[i-2], buildings[i]) - buildings[i-1] + 1)
        for i in range(n-3, 0, -2):
            suffix[i] = suffix[i+2] + max(0, max(buildings[i], buildings[i+2]) - buildings[i+1] + 1)
        ans = None
        for i in range(0, n, 2):
            ans = prefix[i] + suffix[i+1] if ans is None else min(ans, prefix[i] + suffix[i+1])
    print(ans)