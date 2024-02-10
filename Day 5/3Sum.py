def threeSum(nums: list[int]) -> list[list[int]]:
    nums.sort()
    n = len(nums)
    res = []
    for i, num in enumerate(nums):
        if i>=n-2 or num>0: break
        if i>0 and nums[i-1] == num: continue
        
        l, r = i+1, n-1
        while l<r:
            total = num + nums[l] + nums[r]
            if total>0:
                r-=1
            elif total<0:
                l+=1
            else:
                res.append([num, nums[l], nums[r]])
                l+=1
                while nums[l] == nums[l-1]  and l<r: l+=1
    return res
                
    # ==============================================
    # nums = sorted(nums)
    # n = len(nums)
    # ans = set()
    # for i in range(n-2):
    #     l, r = i+1, n-1
    #     while(l<r):
    #         if(nums[i]+nums[l]+nums[r] == 0):
    #             ans.add((nums[i],nums[l],nums[r]))
    #             r-=1
    #             l+=1
    #         elif(nums[i]+nums[l]+nums[r] > 0):
    #             r-=1
    #         elif(nums[i]+nums[l]+nums[r] < 0):
    #             l+=1
            
    # return list(map(list, ans))

def main():
    nums = eval(input())
    print(threeSum(nums))

if __name__ == '__main__':
    main()