t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    
    i, j = 0, len(s) - 1
    while i <= j and s[i] == s[j]:
        i += 1
        j -= 1
    if s[i] <= s[j] or i == j:
        print(s)
    else:
        print(s[::-1]+s)