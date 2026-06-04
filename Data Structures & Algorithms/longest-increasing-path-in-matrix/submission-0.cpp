class Solution {
public: 

    vector<vector<int>> dp;
    int n,m;
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        dp = vector<vector<int>> (n, vector<int>(m,0));

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(mat,i,j));
            }
        }
        return ans;
    }

    int solve(vector<vector<int>> mat, int i, int j){
        
        if(dp[i][j] != 0) return dp[i][j];
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        int res = 1;
        for(int k=0;k<4;k++){
            int row = i + dx[k];
            int col = j + dy[k];

            if(row >= 0 && row <n && col >= 0 && col < m && mat[i][j] < mat[row][col]){
                res = max(res, 1 + solve(mat,row,col));
            }
        }
        return dp[i][j] = res;
    

    }



};
