def search(nums: list[int], target: int) -> int:
    l, r = 0, len(nums)-1
    
    while(l<=r):
        mid = (l+r)//2
        
        if nums[mid] == target:
            return mid
        # in left sorted
        if nums[mid] >= nums[l]:
            if target > nums[mid] or target < nums[l]:
                l = mid+1
            else:
                r = mid-1
        # in right sorted
        else:
            if target < nums[mid] or target > nums[r]:
                r = mid-1
            else:
                l = mid+1
    return -1
    

def main():
    nums = eval(input())
    target = int(input())
    print(search(nums, target))

if __name__ == '__main__':
    main()