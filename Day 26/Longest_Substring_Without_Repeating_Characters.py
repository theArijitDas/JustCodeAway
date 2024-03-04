from typing import List
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        i, j = 0, 0
        hashSet = set()
        ans = 0
        while j < len(s):
            if s[j] not in hashSet:
                hashSet.add(s[j])
                ans = max(ans, j-i+1)
            else:
                while s[i] != s[j]:
                    hashSet.remove(s[i])
                    i += 1
                i += 1
            j += 1
        return ans

def main():
    # Take input
    s = eval(input())
    # Print solution
    print(Solution().lengthOfLongestSubstring(s))

if __name__ == '__main__':
    main()