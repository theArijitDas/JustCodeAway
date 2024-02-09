def isPalindrome(s: str) -> bool:
    s = s.lower()
    n = len(s)
    i, j = 0, n-1
    while(not s[i].isalnum() and i<n-1): i+=1
    while(not s[j].isalnum() and j>0): j-=1
    while(i<j):
        if not s[i].isalnum():
            while(not s[i].isalnum() and i<n): i+=1
        if not s[j].isalnum():
            while(not s[j].isalnum() and j>=0): j-=1
        if s[i] != s[j]:
            return False
        i, j = i+1, j-1
    return True

def main():
    s = input()
    print(isPalindrome(s))

if __name__ == '__main__':
    main()