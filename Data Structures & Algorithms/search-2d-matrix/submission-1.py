class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0]) # get the number of ROWS and the numbers of elements in the first row (aka the number of COLS)

        l, r = 0, ROWS* COLS - 1 # start of the flattened matrix, end of the flattened matrix
        while l <= r:
            m = l + (r-l) // 2 # get the midpoint
            row, col = m // COLS, m % COLS # get the 2D coordinates 

            if target < matrix[row][col]:
                r = m -1
            elif target > matrix[row][col]:
                l = m + 1
            else:
                return True
        return False