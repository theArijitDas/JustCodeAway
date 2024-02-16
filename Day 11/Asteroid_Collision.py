def asteroidCollision(asteroids: list[int]) -> list[int]:
    stack = []
    for a in asteroids:
        while stack and stack[-1]>0 and a<0:
            diff = a + stack[-1]
            if diff<=0: stack.pop()
            if diff>=0: a = 0
        if a:
            stack.append(a)
                
    return stack

def main():
    asteroids = eval(input())
    print(asteroidCollision(asteroids))

if __name__ == '__main__':
    main()