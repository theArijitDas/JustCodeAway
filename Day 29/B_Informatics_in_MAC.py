t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    
    MEX = 5
    flag = [True for _ in range(n)]
    for elem in arr:
        flag[elem] = False
    for i in range(n):
        if flag[i]:
            MEX = i
            break
    
    if MEX == 0:
        print(n)
        for i in range(n):
            print(i+1, i+1)
    else:
        idx = set()
        temp = set()
        for i in range(n):
            if arr[i] < MEX:
                temp.add(arr[i])
            if len(temp) == MEX:
                idx.add(i+1)
                temp.clear()
            if len(idx) == 2:
                break
        if len(idx) > 1:
            print(2)
            for x in idx:
                print(1, x)
                print(x+1, n)
                break
        else:
            print(-1)