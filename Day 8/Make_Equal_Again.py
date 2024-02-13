t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    if n<2:
        ans = 0
    elif n == 2:
        ans = 1
    i, j = 0, n-1
    while(arr[i] == arr[0] and i<n-1): i+=1
    while(arr[j] == arr[n-1] and j>=i): j-=1
    if arr[0] == arr[n-1]:
        ans = j-i+1
    else:
        ans = n - max(i, n-j-1)
    print(ans)