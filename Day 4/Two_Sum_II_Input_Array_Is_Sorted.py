def twoSum(nums: list[int], target: int) -> list[int]:
    n = len(nums)
    i, j = 0, n-1
    while(i<j):
        if nums[i] + nums[j] == target:
            return [i+1, j+1]
        if (nums[i]+nums[j]) > target:
            j-=1
        if (nums[i]+nums[j]) < target:
            i+=1

def main():
    nums = eval(input())
    target = int(input())
    print(twoSum(nums, target))

if __name__ == '__main__':
    main()