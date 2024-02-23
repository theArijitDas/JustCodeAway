def searchMatrix(matrix: list[list[int]], target: int) -> bool:
    top, bottom = 0, len(matrix)-1
    while(top <= bottom):
        row = top + (bottom - top)//2
        if matrix[row][-1] < target: top = row+1
        elif matrix[row][0] > target: bottom = row-1
        else: break
    
    if not (top<=bottom): return False
    
    left, right = 0, len(matrix[0])-1
    while(left<=right):
        mid = (left+right)//2
        if matrix[row][mid] == target: return True
        elif matrix[row][mid] > target: right = mid-1
        else: left = mid+1
    return False

def main():
    matrix = eval(input())
    target = int(input())
    print(searchMatrix(matrix, target))

if __name__ == '__main__':
    main()