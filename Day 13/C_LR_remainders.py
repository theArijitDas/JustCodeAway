t = int(input())
for _  in range(t):
    n, m = tuple(map(int, input().strip().split()))
    a = list(map(int, input().strip().split()))
    s = input()
    # if len(s) > 1:
    l, r = 0, n-1
    for c in s[:-1]:
        if c == 'L': l+=1
        else: r-=1
    prod = a[l]%m
    ans = [0]*n
    for i, c in enumerate(reversed(s[:-1])):
        ans[n-i-1] = prod%m
        if c == 'L':
            l-=1
            prod*=(a[l]%m)
        else:
            r+=1
            prod*=(a[r]%m)
    ans[0] = prod%m
    # else:
    #     ans = [a[0]%m]
    print(*ans)