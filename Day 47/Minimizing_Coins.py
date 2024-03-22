from io import open
import sys
output = sys.stdout.write

I = iter(open(0))
n, x = map(int, next(I).strip().split())
arr = list(map(int, next(I).strip().split()))
dp = [float("inf") for _ in range(x+1)]
for i in range(n+1): dp[0] = 0
    
for k in range(1, x+1):
    for i in range(n):
        if k - arr[i] >= 0:
            dp[k] = min(dp[k], dp[k - arr[i]] + 1)

dp[x] = -1 if (dp[x] == float("inf")) else dp[x]
output(str(dp[x]))