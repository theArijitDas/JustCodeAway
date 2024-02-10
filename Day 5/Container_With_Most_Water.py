def maxArea(height: list[int]) -> int:
    n, ans = len(height), 0
    i, j = 0, n-1
    while i<j:
        ans = max(ans, (j-i)*min(height[i], height[j]))
        if height[i]>height[j]: j-=1
        else: i+=1
    return ans
    # ======================================================
    # for i in range(n-1):
    #     for j in range(i+1, n):
    #         ans = max(ans, (j-i)*min(height[i], height[j]))
    # return ans

def main():
    height = eval(input())
    print(maxArea(height))

if __name__ == '__main__':
    main()