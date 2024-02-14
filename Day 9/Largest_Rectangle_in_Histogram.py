def largestRectangleArea(heights: list[int]) -> int:
    stack = []
    ans = 0
    for i, h in enumerate(heights):
        if stack:
            j = i
            while(stack and stack[-1][1] >  h):
                j, ht = stack.pop()
                ans = max(ans, (i-j)*ht)
            stack.append((j, h))
        else:
            stack.append((i, h))
    for i, h in stack:
        ans = max(ans, (len(heights)-i)*h)
    return ans

def main():
    heights = eval(input())
    print(largestRectangleArea(heights))

if __name__ == '__main__':
    main()