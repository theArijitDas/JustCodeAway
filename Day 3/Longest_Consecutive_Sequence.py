def longestConsecutive(nums: list[int]) -> int:
    nums = set(nums)
    ans = 0
    for num in nums:
        curr_ans = 0
        if num-1 in nums:
            continue
        temp = num
        while(temp in nums):
            curr_ans+=1
            temp += 1
        ans = max(ans, curr_ans)
    return ans

def main():
    nums = eval(input())
    print(longestConsecutive(nums))

if __name__ == '__main__':
    main()