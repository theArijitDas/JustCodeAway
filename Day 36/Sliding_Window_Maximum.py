from typing import List
import sys
from collections import deque
input = sys.stdin.readline


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        ans = []
        i, j = 0, 0
        while j < k:
            while len(dq) > 0 and dq[-1] < nums[j]:
                dq.pop()
            dq.append(nums[j])
            j += 1
        
        ans.append(dq[0])
        for j in range(k, len(nums)):
            if dq[0] == nums[i]:
                dq.popleft()
            while len(dq) > 0 and nums[j] > dq[-1]:
                dq.pop()
            dq.append(nums[j])
            ans.append(dq[0]) 
            i += 1
        
        return ans          

def main():
    # Take input
    nums = eval(input())
    k = int(input())
    # Print solution
    print(Solution().maxSlidingWindow(nums, k))

if __name__ == '__main__':
    main()