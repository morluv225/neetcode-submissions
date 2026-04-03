class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        if(r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] == '0') 
        {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r, c +1);
        dfs(grid, r, c-1);
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
    }

    int numIslands(vector<vector<char>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        if(numRows == 0) return 0;

        int islands = 0;

        for(int r = 0; r < numRows; ++r)
        {
            for(int c = 0; c < numCols; ++c)
            {
                if(grid[r][c] == '1')
                {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};
