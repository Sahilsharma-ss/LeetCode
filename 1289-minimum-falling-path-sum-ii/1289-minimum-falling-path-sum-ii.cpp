#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int solve(int row, int prevCol, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row == n) return 0;

        if (dp[row][prevCol+1] != -1) return dp[row][prevCol+1];

        int ans = INT_MAX;
        for (int col = 0; col < n; col++) {
            if (col == prevCol) continue; // skip same column
            int val = grid[row][col] + solve(row + 1, col, grid, dp);
            ans = min(ans, val);
        }
        return dp[row][prevCol+1] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, grid, dp);
    }
};
