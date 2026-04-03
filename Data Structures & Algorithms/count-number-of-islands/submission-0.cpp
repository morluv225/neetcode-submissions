class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        // Base cases: out of bounds or water/visited cell
        if (r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] == '0') {
            return;
        }

        // Mark current cell as visited (e.g., change '1' to '0')
        grid[r][c] = '0'; 

        // Recursively visit neighbors
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int numRows = grid.size();
        if (numRows == 0) return 0; // Handle empty grid
        int numCols = grid[0].size();

        int islandCount = 0;

        // Iterate through each cell of the grid
        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                // If a '1' (land) is found, it's a new island
                if (grid[r][c] == '1') {
                    islandCount++;
                    // Perform DFS to mark all connected land cells as visited
                    dfs(grid, r, c);
                }
            }
        }
        return islandCount;
    }
};
