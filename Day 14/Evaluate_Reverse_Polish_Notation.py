def evalRPN(tokens: list[str]) -> int:
    stack = []
    for t in tokens:
        # if t.isnumeric():
        try:
            stack.append(int(t))
        except:
            x, y = stack.pop(), stack.pop()
            if t == '+':
                stack.append(y+x)
            elif t == '-':
                stack.append(y-x)
            elif t == '*':
                stack.append(y*x)
            elif t == '/':
                stack.append(int(y/x))
        # print(stack)
    return stack[0]

def main():
    token = eval(input())
    print(evalRPN(token))

if __name__ == '__main__':
    main()