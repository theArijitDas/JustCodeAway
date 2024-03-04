from typing import List
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) >  len(s2): return False
        
        count1, count2 = [0]*26, [0]*26
        for i in range(len(s1)):
            count1[ord(s1[i]) - ord('a')] += 1
            count2[ord(s2[i]) - ord('a')] += 1

        matches = 0
        for i in range(26):
            if count1[i] == count2[i]:
                matches += 1
        
        i, j = 0, len(s1)
        while j < len(s2):
            
            if matches == 26:
                return True
            
            count2[ord(s2[i]) - ord('a')] -= 1
            if count1[ord(s2[i]) - ord('a')] == count2[ord(s2[i]) - ord('a')]:
                matches += 1
            elif count1[ord(s2[i]) - ord('a')] == count2[ord(s2[i]) - ord('a')] + 1:
                matches -= 1
            i += 1
            
            count2[ord(s2[j]) - ord('a')] += 1
            if count1[ord(s2[j]) - ord('a')] == count2[ord(s2[j]) - ord('a')]:
                matches += 1
            elif count1[ord(s2[j]) - ord('a')] == count2[ord(s2[j]) - ord('a')] - 1:
                matches -= 1
            j += 1
            
        return False
        

def main():
    # Take input
    s1 = input()
    s2 = input()
    # Print solution
    print(Solution().checkInclusion(s1, s2))

if __name__ == '__main__':
    main()