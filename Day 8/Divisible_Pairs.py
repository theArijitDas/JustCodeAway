t = int(input())
for _ in range(t):
    n, x, y = tuple(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    # mod_x, mod_y = defaultdict(set), defaultdict(set)
    hashMap = {}
    ans = 0
    for i, num in enumerate(arr):
        # s1 = mod_x[(x - num%x)%x]
        # s2 = mod_y[num%y]
        t_ = ((x - num%x)%x, num%y)
        ans += hashMap.get(t_, 0)
        hashMap[(num%x, num%y)] = hashMap.get((num%x, num%y), 0) + 1
        # mod_x[num%x].add(i)
        # mod_y[num%y].add(i)
    print(ans)