t = int(input())
min_budget = 0
for i in range(7):
    min_budget+=2**i
for _ in range(t):
    budget = int(input())
    if budget>=min_budget:
        print("YES")
    else:
        print("NO")