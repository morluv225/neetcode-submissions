class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(); // get the number of rows
        int COLS = matrix[0].size(); // get the number of cols

        // treat the matrix like a 1D array
        // and set the left and right pointers
        // Ex. ROWS = 3, COLS = 4, the valid indices of the virtual array is 0 ... 11 (ROWS*COLS-1)
        int l = 0, r = ROWS * COLS - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // For any mispoint, convert the 1D index to 2D coordinates
            // row = m / COLS: Integer division jumps to the correct row.
            // col = m % COLS: Remainder tell you how far into the row you are
            // Ex: COLS = 4 & m = 9; row = 9/4 = 2. col = 9%4 = 1. So m = 9, corresponds to matrix[2][1].
            int row = mid / COLS, col = mid % COLS;
            if (target > matrix[row][col]) {
                l = mid + 1;
            } else if (target < matrix[row][col]) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
