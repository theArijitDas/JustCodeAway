def carFleet(target: int, position: list[int], speed: list[int]) -> int:
    
    pos_sp = [(position[i], speed[i]) for i in range(len(position))]
    pos_sp = sorted(pos_sp, key=lambda x: x[0])
    
    stack = []
    for p, s in pos_sp:
        while stack:
            p1, s1 = stack[-1]
            t = (target - p)//s
            t1 = (target - p1)//s1
            if t1 <= t:
                stack.pop()
            else:
                break
        stack.append((p, s))
    return len(stack)

def main():
    target = int(input())
    position = eval(input())
    speed = eval(input())
    
    print(carFleet(target, position, speed))

if __name__ == '__main__':
    main()