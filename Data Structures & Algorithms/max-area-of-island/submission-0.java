class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] vis = new int[n][m];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    ans = Math.max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }

    int dfs(int[][] grid, int[][] vis, int i, int j) {
        int n = grid.length;
        int m = grid[0].length;
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if (vis[i][j] == 1 || grid[i][j] == 0)
            return 0;
        vis[i][j] = 1;
        int ans = dfs(grid, vis, i + 1, j) + dfs(grid, vis, i - 1, j) + dfs(grid, vis, i, j - 1)
            + dfs(grid, vis, i, j + 1) + 1;
        return ans;
    }
}
