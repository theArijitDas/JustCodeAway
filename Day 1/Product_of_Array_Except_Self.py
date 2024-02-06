def productExceptSelf(nums: list[int]) -> list[int]:
    
    # ============================================================= O(n),O(1) without division
    n = len(nums)
    res = [1]*n
    
    prefix = 1
    for i in range(n):
        res[i] = prefix
        prefix*=nums[i]
    
    suffix = 1
    for i in range(n-1, -1, -1):
        res[i] *= suffix
        suffix*=nums[i]
    
    return res
    # ============================================================= O(n),O(n)
    # n = len(nums)
    # prefix_prod, suffix_prod, res = [1]*n, [1]*n, [1]*n
    
    # for i in range(1, n):
    #     prefix_prod[i] = prefix_prod[i-1] * nums[i-1]
    # for i in range(n-2, -1, -1):
    #     suffix_prod[i] = suffix_prod[i+1] * nums[i+1]
    # for i in range(n):
    #     res[i] = prefix_prod[i] * suffix_prod[i]
    
    # return res 
    
    # ============================================================= O(n), O(1) using division
    # zero_idx = -1
    # prod = 1
    # for idx, num in enumerate(nums):
    #     if num==0:
    #         if zero_idx == -1:
    #             zero_idx = idx
    #         else:
    #             return [0]*len(nums)
    #     else:
    #         prod*=num
    # if zero_idx == -1:
    #     return [prod//num for num in nums]
    # res = [0]*len(nums)
    # res[zero_idx] = prod
    # return res
    # =============================================================

def main():
    nums = eval(input())
    print(productExceptSelf(nums))

if __name__ == '__main__':
    main()