t = int(input())
for _ in range(t):
    n = int(input())
    s1, s2 = input(), input()
    m1, m2 = map(lambda x: ord(x) - ord('A'), list(s1)), list(map(lambda x: ord(x) - ord('A'), list(s2)))
    ans = [0]*n
    for i, (j, k) in enumerate(zip(m1, m2)):
        temp = (k-j)
        temp = temp+26 if temp<0 else temp
        ans[i] = ((temp%3)*26 + temp)//3
    print(*ans)