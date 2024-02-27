class TimeMap:

    def __init__(self):
        self.data = {}        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.data:
            self.data[key] = []
        self.data[key].append([value, timestamp])        

    def get(self, key: str, timestamp: int) -> str:
        ans = ""
        values = self.data.get(key, [])
        
        l, r = 0, len(values)-1
        while l <= r:
            mid = (l+r)//2
            if values[mid][1] <= timestamp:
                ans = values[mid][0]
                l = mid+1
            else:
                r = mid-1
        
        return ans

def main():
    func = eval(input())
    args = eval(input())
    
    res = []
    
    for f, a in zip(func, args):
        if f == "TimeMap":
            obj = TimeMap()
            res.append(None)
        elif f == "set":
            obj.set(*a)
            res.append(None)
        elif f == "get":
            res.append(obj.get(*a))
    print(res)

if __name__ == '__main__':
    main()