class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(j<0 || j>=grid[0].size()) return 1e9;
        if(i==0) return grid[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int s=grid[i][j]+solve(i-1,j-1,grid,dp);
        int ld=grid[i][j]+solve(i-1,j,grid,dp);
        int rd=grid[i][j]+solve(i-1,j+1,grid,dp);
        return dp[i][j]= min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            mini=min(mini,solve(m-1,i,matrix,dp));
        }
        return mini;
    }
};