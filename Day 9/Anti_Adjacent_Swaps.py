def solve(n: int, a: list):
    if n==1: return True
    elif n==2: return a[0]<=a[1]
    elif n==3: return min(a[0], a[2]) <= a[1] <= max(a[0], a[2])
    elif n==4: return min(a[0], a[2]) <= min(a[1], a[3]) and max(a[0], a[2]) <= max(a[1], a[3])
    return True

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    if solve(n, a):
        print("YES")
    else:
        print("NO")        