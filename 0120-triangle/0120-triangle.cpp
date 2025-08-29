class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (i == n - 1) {
            return triangle[i][j];
        }
        if (dp[i][j] != 1e9) return dp[i][j];
        // return dp[i][j] =triangle[i][j] + min(solve(i + 1, j, triangle, dp),(j + 1 < triangle[i + 1].size() ? solve(i + 1, j + 1, triangle, dp): (int)1e9));
        return dp[i][j] = triangle[i][j] +
                  min(solve(i + 1, j, triangle, dp),
                      solve(i + 1, j + 1, triangle, dp));

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        m = triangle[n - 1].size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].assign(triangle[i].size(), 1e9);
        }
        return solve(0, 0, triangle, dp);
    }
};