t = int(input())
for _ in range(t):
    n, m, k = tuple(map(int, input().strip().split()))
    a = sorted(map(int, input().strip().split()))
    b = sorted(map(int, input().strip().split()))
    
    seta = set()
    for num in a:
        if num<=k: seta.add(num)
    
    setb = set()
    for num in b:
        if num<=k: setb.add(num)
    
    if len(seta)<k//2 or len(setb)<k//2:
        print("NO")
    else:
        setab = seta.union(setb)
        for num in range(1, k+1):
            if num not in setab:
                print("NO")
                break
        else:
            print("YES")