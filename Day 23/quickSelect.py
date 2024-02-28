def select(A: list, l: int, r: int):
    pivot = A[r]
    i = l
    for j in range(l, r):
        if A[j] <= pivot:
            A[i], A[j] = A[j], A[i]
            i+=1
    A[i], A[r] = A[r], A[i]
    return i

def quickSelect(A, k, l, r):
    i = select(A, l, r)
    if i==k:
        return A[k]
    elif i>k:
        return quickSelect(A, k, l, i-1)
    else:
        return quickSelect(A, k, i+1, r)

if __name__ == '__main__':
    A = list(map(int, input().strip().split()))
    k = int(input())
    print(quickSelect(A, k-1, 0, len(A)-1))