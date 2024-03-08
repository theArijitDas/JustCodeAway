t = int(input())
for _ in range(t):
    n, k = tuple(map(int, input().strip().split()))
    a = list(map(int, input().strip().split()))
    
    def is_possible(m):
        for i in range(len(a)):
            temp = 0
            for j in range(i, len(a)):
                if m - (j - i) > a[j]:
                    temp += m - (a[j] + (j - i))
                elif k >= temp:
                    return True
        return False
                    
    ans = 0
    l, r = 0, max(a) + k
    while l <= r:
        m = (l + r)//2
        if is_possible(m):
            ans = m
            l = m + 1
        else:
            r = m - 1
    print(ans)