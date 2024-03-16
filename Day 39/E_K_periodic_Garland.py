import sys
input = sys.stdin.readline
output = sys.stdout.write

I = iter(open(0))
T = int(next(I))
ans = [0] * T
for t in range(T):
    n, k = map(int, next(I).split())
    s = list(map(int, iter(next(I).strip())))
    pref = [0] * n
    
    pref[0] = s[0]
    for i in range(1, n):
        pref[i] = pref[i-1] + s[i]
    
    dp = {(0, 0): 0, (0, 1) : 0} # dp[(i, b)] represents the cost that s[:i+1] is good, when s[i] == b
    def solve(i, b):
        
        # overlapping problem
        if (i, b) in dp:
            return dp[(i, b)]
        
        # recursion
        if b == 1:
            type1 = pref[i - 1]
            type2 = ((pref[i - 1] - pref[i - k]) + solve(i-k, 1)) if i >= k else float("inf")
            dp[(i, b)] = min(type1, type2) + (s[i] == 0)
        else:
            dp[(i, b)] = min(solve(i-1, 0), solve(i-1, 1)) + (s[i] == 1)
        return dp[(i, b)]   
    
    ans[t] = min(solve(n-1, 1), solve(n-1, 0))

output("\n".join(map(str, ans)))