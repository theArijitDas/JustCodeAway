def solve(i: int, T: str, N: int, Bags: list[int, str], dp: dict):
    if T == "":
        return 0
    if i == N:
        return float("inf")
    
    if (i, T) not in dp:
        not_pick = solve(i + 1, T, N, Bags, dp)
        
        pick = float("inf")
        for j in range(1, Bags[i][0] + 1):
            if Bags[i][j] == T[:len(Bags[i][j])]:
                pick = min(pick, 1 + solve(i+1, T[len(Bags[i][j]):], N, Bags, dp))
    
        print(f"{pick = } | {not_pick = }")
        dp[(i, T)] = min(pick, not_pick)
        
    return dp[(i, T)]

def main():
    T: int = input()
    N: int = int(input())
    Bags: list[int, str] = [None for _ in range(N)]
    for i in range(N):
        Bags[i] = input().split()
        Bags[i][0] = int(Bags[i][0])
    
    dp = {}
    cost: int = solve(0, T, N, Bags, dp)
    if cost != float("inf"):
        print(cost)
    else:
        print(-1)


if __name__ == "__main__":
    main()