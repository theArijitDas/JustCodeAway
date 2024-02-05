def topKFrequent(nums: list[int], k: int) -> list[int]:
    n = len(nums)
    counts = {}
    freq = [[] for _ in range(n+1)]
    
    for num in nums:
        counts[num] = counts.get(num, 0)+1
    
    for num, count in counts.items():
        freq[count].append(num)
    
    res = []
    for i in range(n, 0, -1):
        for num in freq[i]:
            res.append(num)
            if len(res) == k:
                return res

def main():
    nums = eval(input())
    k = int(input())
    res = topKFrequent(nums, k)
    print(res)

if __name__ == '__main__':
    main()