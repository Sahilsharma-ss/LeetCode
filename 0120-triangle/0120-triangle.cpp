class Solution {
public:
    int n, m;
    // int solve(int i, int j, vector<vector<int>>& triangle,
    //     vector<vector<int>>& dp) {
    //     if (i == n - 1) {
    //         return triangle[i][j];
    //     }
    //     if (dp[i][j] != 1e9) return dp[i][j];
    //     // return dp[i][j] =triangle[i][j] + min(solve(i + 1, j, triangle, dp),(j + 1 < triangle[i + 1].size() ? solve(i + 1, j + 1, triangle, dp): (int)1e9));
    //     return dp[i][j] = triangle[i][j] +min(solve(i + 1, j, triangle, dp),solve(i + 1, j + 1, triangle, dp));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        m = triangle[n - 1].size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].assign(triangle[i].size(), 0);
        }
        // return solve(0, 0, triangle, dp);
        dp[0][0]=triangle[0][0];
        for(int j=0;j<m;j++)
        {
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,diag);
            }
        }
        return dp[0][0];
    }
};