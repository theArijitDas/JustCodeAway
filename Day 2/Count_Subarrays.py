t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    res = {i:1 for i in range(1, n+1)}
    for i in range(n):
        sum_ = arr[i]
        for j in range(i+1, n):
            sum_+=arr[j]
            if(sum_>n): break
            res[sum_]+=1
    print(" ".join(list(map(str, res.values()))))