import sys
input = sys.stdin.readline
M = 10 ** 9 + 7

dp = [1 for _ in range(10)]
for i in range(2*10**5):
    dp.append((dp[i] + dp[i+1]) % M)

t = int(input())
for _ in range(t):
    n, m = input().split()
    m = int(m)
    
    ans = 0
    for d in n:
        ans = (ans + dp[int(d) + m]) % M
    
    print(ans)