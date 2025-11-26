class Solution {
public:
    int n, m, k;
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;   // dp[i][j][rem]

    int solve(int i, int j, int rem, vector<vector<int>>& grid) 
    {
        if(i == n-1 && j == m-1) {
            return rem%k==0;
        }

        if(dp[i][j][rem] != -1) 
            return dp[i][j][rem];

        int ans = 0;
        int newRem;

        // Move Down
        if(i + 1 < n) {
            newRem = (rem + grid[i+1][j]) % k;
            ans = (ans + solve(i+1, j, newRem, grid)) % MOD;
        }

        // Move Right
        if(j + 1 < m) {
            newRem = (rem + grid[i][j+1]) % k;
            ans = (ans + solve(i, j+1, newRem, grid)) % MOD;
        }

        return dp[i][j][rem] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int K) {
        n = grid.size();
        m = grid[0].size();
        k = K;
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(0, 0, grid[0][0] % k, grid);
    }
};
