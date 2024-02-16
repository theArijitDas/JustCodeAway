def dailyTemperatures(temperatures: list[int]) -> list[int]:
    stack = [] # (index, temp)
    res = [0]*len(temperatures)
    for i, temp in enumerate(temperatures):
        # print(f"\n{(i, temp) = }")
        if not stack:
            stack.append((i, temp))
            # print((f"{stack = }"))
            continue
        while stack and temp > stack[-1][1]:
            j, t = stack.pop()
            # print(f"{(j, t) = }")
            res[j] = (i-j)
            # print(f"{res = }")
        stack.append((i, temp))
        # print(f"{stack = }")
    return res
            

def main():
    temp = eval(input())
    print(dailyTemperatures(temp))

if __name__ == '__main__':
    main()