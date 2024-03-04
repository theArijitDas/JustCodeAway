from typing import List
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        # =====================================================O(n)
        i, j = 0, 0
        maxf = 0
        hashArr = [0 for _ in range(26)]
        ans = 0
        while j < len(s):
            hashArr[ord(s[j]) - ord('A')] += 1
            maxf = max(maxf, hashArr[ord(s[j]) - ord('A')])
            while (j - i + 1 - maxf) > k:
                hashArr[ord(s[i]) - ord('A')] -= 1
                i += 1  
            ans = max(ans, j - i + 1)
            j += 1
        return ans
        
        
        # =====================================================O(26*n)
        # i, j = 0, 0
        # hashArr = [0 for _ in range(26)]
        # ans = 0
        # while j < len(s):
        #     hashArr[ord(s[j]) - ord('A')] += 1
        #     while (j - i - max(hashArr) + 1) > k:
        #         hashArr[ord(s[i]) - ord('A')] -= 1
        #         i += 1  
        #     ans = max(ans, j - i + 1)
        #     j += 1
        # return ans
        
            

def main():
    # Take input
    s = input()
    k = int(input())
    # Print solution
    print(Solution().characterReplacement(s, k))

if __name__ == '__main__':
    main()