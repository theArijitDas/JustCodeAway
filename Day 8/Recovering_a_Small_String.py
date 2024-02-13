t = int(input())
for _ in range(t):
    n = int(input())
    ans = ""
    if n < 26+2:
        ans = 'aa' + chr(n-2 + ord('a') - 1)
    elif n < 26+26+1:
        ans = 'a' + chr(n-27 + ord('a') - 1) + 'z'
    else:
        ans = chr(n-26-26 + ord('a') - 1) + 'zz'
    print(ans)