t = int(input())
for _ in range(t):
    n = int(input())
    arr = map(int, input().strip().split())
    hashMap = {}
    res = ''
    for num in arr:
        ch = ord('a')
        while(hashMap.get(chr(ch), 0) > num):
            ch+=1
        res += chr(ch)
        hashMap[chr(ch)] = hashMap.get(chr(ch), 0) + 1
    print(res)
    # =====================TLE====================
    # hashMap = {}
    # res = ''
    # ch = ord('a')
    # for i, num in enumerate(arr):
    #     if num==0:
    #         res += chr(ch)
    #         hashMap[0] = hashMap.get(0, [])
    #         hashMap[0].append(chr(ch))
    #         ch+=1
    #     else:
    #         c = hashMap[num-1].pop()
    #         res+=c
    #         hashMap[num] = hashMap.get(num, [])
    #         hashMap[num].append(c)
    # print(res)                