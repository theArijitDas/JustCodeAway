from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell = 0, 0
        ans = 0
        for i in range(1, len(prices)):
            if prices[buy] > prices[i]:
                buy = i
                sell = i
            if prices[sell] < prices[i]:
                sell = i
                ans = max(ans, prices[sell] - prices[buy])
        return ans

def main():
    # Take input
    prices = eval(input())
    
    # Print solution
    print(Solution().maxProfit(prices))

if __name__ == '__main__':
    main()