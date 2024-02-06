def encode(strs: list[str]):
    return ''.join([f'{len(s)}#'+s for s in strs])

def decode(st: str):
    l = []
    i=0
    while i<len(st):
        j=i
        while(st[j] != '#'): j+=1
        num = int(st[i:j])
        l.append(st[j+1: j+num+1])
        i=j+num+1
    return l
        

def main():
    lst = eval(input())
    en = encode(lst)
    de = decode(en)
    print(de)

if __name__ == '__main__':
    main()