def generateParenthesis(n: int) -> list[str]:
    stack = []
    res = []
    def backTracking(openN, closeN):
        if openN == closeN == n:
            res.append("".join(stack))
            return
        if openN < n:
            stack.append('(')
            backTracking(openN+1, closeN)
            stack.pop()
        if closeN < openN:
            stack.append(')')
            backTracking(openN, closeN+1)
            stack.pop()
        return
    backTracking(0, 0)
    return res

def main():
    n = int(input())
    print(generateParenthesis(n))

if __name__ == '__main__':
    main()