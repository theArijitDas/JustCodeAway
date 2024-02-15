t = int(input())
for _ in range(t):
    k, x, a = tuple(map(int, input().strip().split()))
    print(f'{2*k*(x+1) = } | {x*(x+1) = } and {(x+1)*(x+2) = }')
    print(f'{x = } | {k = }')
    # if (((2*k*(x+1)) > (x*(x+1))) and (2*a > (x+1)*(x+2))): print("YES")
    # else: print("NO")