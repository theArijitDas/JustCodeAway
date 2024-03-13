from typing import List

class Solution:
    dp = [-1] * 46
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        if self.dp[n] != -1:
            return self.dp[n]
        self.dp[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        return self.dp[n]

def main():
    # Take input
    n = int(input())
    # Print solution
    print(Solution().climbStairs(n))

if __name__ == '__main__':
    main()