public class Solution {
    public List<List<int>> PacificAtlantic(int[][] heights) {
        int numRows = heights.Length;
        int numCols = heights[0].Length;

        var pacific = new Queue<(int r, int c)>();
        var atlantic = new Queue<(int r, int c)>();

        var pVisited = new HashSet<(int r, int c)>();
        var aVisited = new HashSet<(int r, int c)>();

        // Pacific borders
        for (int r = 0; r < numRows; r++)
        {
            pacific.Enqueue((r, 0));
            pVisited.Add((r, 0));
        }
        for (int c = 0; c < numCols; c++)
        {
            pacific.Enqueue((0, c));
            pVisited.Add((0, c));
        }

        // Atlantic borders
        for (int c = 0; c < numCols; c++)
        {
            atlantic.Enqueue((numRows - 1, c));
            aVisited.Add((numRows - 1, c));
        }
        for (int r = 0; r < numRows; r++)
        {
            atlantic.Enqueue((r, numCols - 1));
            aVisited.Add((r, numCols - 1));
        }

        // BFS both oceans
        bfs(pacific, pVisited, heights);
        bfs(atlantic, aVisited, heights);

        var result = new List<List<int>>();

        for (int r = 0; r < numRows; r++)
        {
            for (int c = 0; c < numCols; c++)
            {
                if (pVisited.Contains((r, c)) && aVisited.Contains((r, c)))
                {
                    result.Add(new List<int> { r, c });
                }
            }
        }

        return result;
    }

    public void bfs(
        Queue<(int r, int c)> queue,
        HashSet<(int r, int c)> visited,
        int[][] heights)
    {
        int rows = heights.Length;
        int cols = heights[0].Length;

        int[][] dirs = new int[][]
        {
            new int[] { 1, 0 },
            new int[] { -1, 0 },
            new int[] { 0, 1 },
            new int[] { 0, -1 }
        };

        while (queue.Count > 0)
        {
            var (r, c) = queue.Dequeue();

            foreach (var d in dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                if (visited.Contains((nr, nc)))
                    continue;

                if (heights[nr][nc] < heights[r][c])
                    continue;

                visited.Add((nr, nc));
                queue.Enqueue((nr, nc));
            }
        }
    }
}
