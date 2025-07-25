class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&vec)
    {
        if(i==0&&j==0) return 1;

        if(i<0||j<0||vec[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up=solve(i-1,j,dp,vec);
        int left=solve(i,j-1,dp,vec);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>>vec(m,vector<int>(n,0));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    vec[i][j]=1;
                }
            }
        }
        return solve(m-1,n-1,dp,vec);
    }

};