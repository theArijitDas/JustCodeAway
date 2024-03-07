from typing import List
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "": return ""
        
        tMap = {}
        sMap = {}
        
        for c in t:
            tMap[c] = 1 + tMap.get(c, 0)
        
        have, need = 0, len(tMap)
        res, resLen = [-1, -1], float("infinity")
        l = 0
        
        for r in range(len(s)):
            
            sMap[s[r]] = 1 + sMap.get(s[r], 0)
            
            if s[r] in t and sMap[s[r]] == tMap[s[r]]:
                have += 1
            
            while have == need:
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = (r - l + 1)
                
                sMap[s[l]] -= 1
                if s[l] in tMap and sMap[s[l]] < tMap[s[l]]:
                    have -= 1
                l += 1
        
        l, r = res
        return s[l: r + 1] if resLen != float("infinity") else ""
                
                

def main():
    # Take input
    s = input()
    t = input()
    
    # Print solution
    print(Solution().minWindow(s, t))

if __name__ == '__main__':
    main()