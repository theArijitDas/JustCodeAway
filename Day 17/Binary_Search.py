def search(nums: list[int], target: int) -> int:
    low, high = 0, len(nums)-1

    while(low <= high):
        mid = low + (high-low)//2
        if nums[mid] == target: return mid
        elif nums[mid] > target:
            high = mid-1
        else:
            low = mid+1
    
    return -1

def main():
    nums = eval(input())
    target = int(input())
    print(search(nums, target))

if __name__ == '__main__':
    main()