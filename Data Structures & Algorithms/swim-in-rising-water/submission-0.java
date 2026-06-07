class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;

        int low = 0;
        int high = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = Math.max(high, grid[i][j]);
            }
        }
        int ans = Integer.MAX_VALUE;
        while (low <= high) {
            int mid = low + (high - low / 2);
            int[][] vis = new int[n][n];
            if (isValidTime(grid, vis, 0, 0, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public boolean isValidTime(int[][] grid, int[][] vis, int i, int j, int time) {
        int n = grid.length;

        if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == 1 || grid[i][j] > time) {
            return false;
        }
        if (i == n - 1 && j == n - 1) {
            return true;
        }
        vis[i][j] = 1;
        return isValidTime(grid, vis, i + 1, j, time) || isValidTime(grid, vis, i - 1, j, time)
            || isValidTime(grid, vis, i, j + 1, time) || isValidTime(grid, vis, i, j - 1, time);
    }
}
