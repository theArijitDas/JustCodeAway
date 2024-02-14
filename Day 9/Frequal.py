N = int(1e6 + 1)
seive = [True]*N
seive[0], seive[1] = False, False
primes = []
for i in range(2, N):
    if seive[i]:
        primes.append(i)
        primes.append(i)
        for j in range(i*i, N, i):
            seive[j] = False

t = int(input())
for _ in range(t):
    n = int(input())
    if n&1:
        print(1, end=" ")
        n-=1
    print(*primes[:n])