import sys
from typing import List
input = sys.stdin.readline
print = sys.stdout.write

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}
        def fun(i: int, total: int):
            if i == -1:
                return 1 if total == 0 else 0
            if (i, total) in dp:
                return dp[(i, total)]
            
            dp[(i, total)] = fun(i-1, total - nums[i]) + fun(i-1, total + nums[i])
            return dp[(i, total)]
        return fun(len(nums)-1, target)
            

# Take input
nums = list(map(int, input().split()))
target = int(input())

# Print solution
print(str(Solution().findTargetSumWays(nums, target)))