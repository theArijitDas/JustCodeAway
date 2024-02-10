def trap(height: list[int]) -> int:
    if not height: return 0
    n = len(height)
    l, r = 0, n-1
    maxL, maxR = height[l], height[r]
    ans = 0
    while(l<r):
        # ans += max(0, min(maxL, maxR) - )
        if maxR < maxL:
            r-=1
            maxR = max(maxR, height[r])
            ans += maxR - height[r]
        else:
            l+=1
            maxL = max(maxL, height[l])
            ans += maxL - height[l]
    return ans
    # ======================= O(n), O(n) ======================
    # n = len(height)
    # prefix, suffix = [0]*n, [0]*n
    # for i in range(1, n):
    #     prefix[i] = max(prefix[i-1], height[i-1])
    # for i in range(n-2, -1, -1):
    #     suffix[i] = max(suffix[i+1], height[i+1])
    # ans = 0
    # for i in range(1, n-1):
    #     ans += max(0, min(prefix[i], suffix[i]) - height[i])
    # return ans

def main():
    height = eval(input())
    print(trap(height))

if __name__ == '__main__':
    main()