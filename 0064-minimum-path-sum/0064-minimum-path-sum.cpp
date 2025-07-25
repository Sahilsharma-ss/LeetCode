class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid)
    {
        if(i==0&&j==0) return grid[i][j];
        if(i<0||j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j] + solve(i-1,j,dp,grid);
        int left=grid[i][j]+solve(i,j-1,dp,grid);
        grid[i][j]=min(up,left);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
    }
};