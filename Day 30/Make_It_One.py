t = int(input())
for _ in range(t):
    l, r = tuple(map(int, input().strip().split()))

    n = r - l + 1
    if n == 1:
        print(-1)
    elif n % 2:
        if l % 2:
            print(l+2, l, l+1, end = " ")
            for i in range(l+3, r, 2):
                print(i+1, i, end = " ")
            print()
        else:
            print(-1)
    else:
        for i in range(l, r, 2):
            print(i + 1, i, end = " ")
        print()