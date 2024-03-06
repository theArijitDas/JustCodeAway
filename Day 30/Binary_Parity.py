t = int(input())

for _ in range(t):
    x = int(input())
    b = bin(x)[2:]
    
    if b.count('1') % 2:
        print("ODD")
    else:
        print("EVEN")