class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        // get the numbers of rows and columns
        int nr = grid.size();
        int nc = grid[0].size();

        // Base case: check for out of bounds/water/already visited cell
        // return 0 because it won't contribue to the max area
        if(r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] == 0) return 0;

        // mark cell as visited
        grid[r][c] = 0;

        // create area variable
        int area = 1;

        // increment area based on the dfs of the cell in every directiom
        area += dfs(grid, r + 1, c); // down 
        area += dfs(grid, r - 1, c); // up
        area += dfs(grid, r, c + 1); // right
        area += dfs(grid, r, c - 1); // left

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        if(numRows == 0) return 0;

        int maxArea = 0;

        for(int r = 0; r < numRows; ++r)
        {
            for(int c = 0; c < numCols; ++c)
            {
                if(grid[r][c] == 1)
                {
                    // get the area from the dfs result
                    // calc maxArea
                    int area = dfs(grid, r, c);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};
