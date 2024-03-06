t = int(input())
for _ in range(t):
    n, m = tuple(map(int, input().strip().split()))
    
    if n >= 2 * m:
        print("YES")
    else:
        print("NO")