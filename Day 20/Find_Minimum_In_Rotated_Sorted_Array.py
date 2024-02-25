def findMin(nums: list[int]) -> int:
    l, r = 0, len(nums)-1
    ans = None
    while(l<=r):
        mid = (l+r)//2
        print(f"{l = } | {r = } | {mid = } | {ans = }")
        if nums[mid] >= nums[l]:
            ans = min(ans, nums[l]) if ans is None else nums[l]
            l = mid+1
        else:
            r = mid-1
        print(f'{ans = }')
    return ans

def main():
    nums = eval(input())
    print(findMin(nums))

if __name__ == '__main__':
    main()