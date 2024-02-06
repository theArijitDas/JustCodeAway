t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    last_differ = [-1]*n
    
    for i in range(1, n):
        if arr[i] != arr[i-1]:
            last_differ[i] = i-1
        else:
            last_differ[i] = last_differ[i-1]
    q = int(input())
    for _ in range(q):
        l, r = tuple(map(int, input().strip().split()))
        l-=1
        r-=1
        if last_differ[r] >= l:
            print(last_differ[r]+1, r+1)
        else:
            print(-1, -1)

# ====================================================
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     arr = list(map(int, input().strip().split()))
#     next_differ = [n]*n
    
#     for i in range(n-2, -1, -1):
#         if arr[i+1] != arr[i]:
#             next_differ[i] = i+1
#         else:
#             next_differ[i] = next_differ[i+1]
    
#     q = int(input())
#     for _ in range(q):
#         l, r = tuple(map(int, input().strip().split()))
#         l-=1
#         r-=1
#         if next_differ[l] <= r:
#             print(l+1, next_differ[l]+1)
#         else:
#             print(-1, -1) 
# ====================================================