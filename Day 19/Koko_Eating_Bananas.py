from math import ceil

def minEatingSpeed(piles: list[int], h: int) -> int:
    low, high = 1, max(piles)
    while low<=high:
        mid = (low+high)//2
        hr = sum(map(lambda x:ceil(x/mid), piles))
        if hr > h:
            low = mid+1
        else:
            ans = mid
            high = mid-1
    return ans

def main():
    piles = eval(input())
    h = int(input())
    
    print(minEatingSpeed(piles, h))

if __name__ == '__main__':
    main()