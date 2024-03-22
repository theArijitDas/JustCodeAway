from io import open
import sys
output = sys.stdout.write
M = 10 ** 9 + 7

n = int([*open(0)][0])
dp = [0 for _ in range(n+1)]
dp[1] = 1

for i in range(2, n+1):
    dp[i] = (i <= 6)
    for j in range(1, 7):
        if i <= j: continue
        dp[i] = (dp[i] + dp[i-j])%M

output(str(dp[n]%M))    