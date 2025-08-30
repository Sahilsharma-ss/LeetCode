class Solution {
public:
    int n;
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(j>=n||j<0) return 1e9;
        if(i==n-1)
        {
            return matrix[i][j];
        }
        if(dp[i][j]!=1e9) return dp[i][j];
        int left=matrix[i][j]+solve(i+1,j-1,matrix,dp);
        int down=matrix[i][j]+solve(i+1,j,matrix,dp);
        int right=matrix[i][j]+solve(i+1,j+1,matrix,dp);
        return dp[i][j]=min({left,down,right});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
           mini=min(mini,solve(0,i,matrix,dp));
        }
        return mini;
    }
};