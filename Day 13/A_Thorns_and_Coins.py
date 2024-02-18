t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans, i = 0, 0
    while(i<len(s)):
        if s[i] == '@': ans+=1
        
        if (i+2)<len(s) and s[i+1] == s[i+2] == '*':
            break
        
        if (i+1)<len(s) and s[i+1] == '*':
            i+=2
        else: i+=1
    print(ans)