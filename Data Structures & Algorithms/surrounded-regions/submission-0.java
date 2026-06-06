class Solution {
    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[][] vis = new int[n][m];
        for(int i=0;i<n;i++){
            dfs(board, vis, i,0);
            dfs(board, vis, i, m-1);
        }
        for(int j=0;j<m;j++){
            dfs(board, vis, 0, j);
            dfs(board, vis, n-1, j);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '-'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    public void dfs(char[][] board, int[][] vis, int i, int j){
        int  n = board.length;
        int m = board[0].length;
        if(i>=n || i < 0 || j >=m || j < 0 || board[i][j] == 'X' || vis[i][j] == 1) return;
        vis[i][j] = 1;
        board[i][j] = '-';
        dfs(board, vis, i + 1, j);
        dfs(board, vis, i - 1, j);
        dfs(board, vis, i, j+1);
        dfs(board, vis, i, j-1);
    }
}
