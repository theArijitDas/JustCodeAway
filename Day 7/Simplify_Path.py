def simplifyPath(path: str) -> str:
    stack = []
    token = ""
    for c in path + "/":
        # print(token)
        if c == '/':
            if token in ["", "."]: token = ""
            elif token == "..":
                if stack: stack.pop()
            else:
                stack.append(token)
            token = ""
            # print(stack)
        else:
            token+=c        
    return '/' + '/'.join(stack)

def main():
    s = eval(input())
    print(simplifyPath(s))
    
if __name__ == '__main__':
    main()