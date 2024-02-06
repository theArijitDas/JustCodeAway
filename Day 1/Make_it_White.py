def solution(n, s):
    i, j = 0, n-1
    while(s[i] == 'W'): i+=1
    while(s[j] == 'W'): j-=1
    return (j-i+1)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        print(solution(n, s))

if __name__ == '__main__':
    main()