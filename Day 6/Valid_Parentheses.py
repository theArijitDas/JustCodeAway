def isValid(s: str) -> bool:
    d = {")":"(",
        "}":"{",
        "]":"["}
    stack = []
    for c in s:
        if c in d:
            if stack and stack[-1] == d[c]: stack.pop()
            else: return False
        else:
            stack.append(c)
    return stack == []

def main():
    s = eval(input())
    print(isValid(s))

if __name__ == '__main__':
    main()