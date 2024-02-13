t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    # print(arr, sum(arr))
    target = sum(arr) / n
    surplus = 0
    for water in arr:
        surplus = surplus + water - target
        if surplus < 0:
            print("NO")
            break
    else:
        print("YES")