from io import open
import sys
input = sys.stdin.readline
output = sys.stdout.write

I = iter(open(0))
T = int(next(I))
ANS = [None] * (2*T)
idx = 0
for _ in range(T):
    n, k = map(int, next(I).split())
    a = list(map(int, next(I).split()))
    d1, d2 = {}, {}
    for i in range(n):
        d1[a[i]] = d1.get(a[i], 0) + 1
    for i in range(n, 2*n):
        d2[a[i]] = d2.get(a[i], 0) + 1
        
    comm = [i for i in d1 if d1[i] == 1]
    A = [i for i in d1 if d1[i] == 2]
    B = [i for i in d2 if d2[i] == 2]
    
    ans = " ".join(map(str, comm[:2*k]))
    if 2*k <= len(comm):
        ANS[idx] = ans.strip()
        ANS[idx +1] = ans.strip()
    else:
        ansA = " ".join(map(str, A[:k - len(comm)//2]))
        ansB = " ".join(map(str, B[:k - len(comm)//2]))
        ansA = " ".join([ans, ansA, ansA])
        ansB = " ".join([ans, ansB, ansB])
        ANS[idx] = ansA.strip()
        ANS[idx+1] = ansB.strip()
    idx += 2

output("\n".join(ANS))