def findOrder(numCourses: int, prerequisites: list[list[int]]) -> list[int]:
    preMap = {c:[] for c in range(numCourses)}
    for c, p in prerequisites:
        preMap[c].append(p)
    
    visited, cycle = set(), set()
    output = []
    
    def dfs(crs):
        if crs in cycle: return False
        if crs in visited: return True
        
        cycle.add(crs)
        for pre in preMap[crs]:
            if not dfs(pre): return False
        
        cycle.remove(crs)
        visited.add(crs)
        output.append(crs)
        return True
    
    for crs in range(numCourses):
        if not dfs(crs): return []
    return output

def main():
    numCourses = int(input())
    prerequisites = eval(input())
    print(findOrder(numCourses, prerequisites))

if __name__ == '__main__':
    main()