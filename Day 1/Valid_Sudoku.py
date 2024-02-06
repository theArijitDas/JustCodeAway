def isValidSudoku(board: list[list[str]]) -> bool:
    # =================================================================
    # check rows
    s = set()
    for i in range(9):
        s.clear()
        for j in range(9):
            if board[i][j] == '.': continue
            if board[i][j] in s:
                return False
            s.add(board[i][j])
    # check cols
    for i in range(9):
        s.clear()
        for j in range(9):
            if board[j][i] == '.': continue
            if board[j][i] in s:
                return False
            s.add(board[j][i])
        print()
    # check boxes
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            s.clear()
            for x in range(i, i+3):
                for y in range(j, j+3):
                    if board[x][y] == '.': continue
                    if board[x][y] in s:
                        return False
                    s.add(board[x][y])
    return True
    # =================================================================

def main():
    board = eval(input())
    print(isValidSudoku(board))

if __name__ == '__main__':
    main()