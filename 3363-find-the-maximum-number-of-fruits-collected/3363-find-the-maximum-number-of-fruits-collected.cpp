class Solution {
public:
    int solve0(int n, vector<vector<int>>& fruits)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=fruits[i][i];
        }
        return cnt;
    }
    int solve(int i, int j, int n, vector<vector<int>>& fruits,vector<vector<int>>&dp) {
        if (i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        if (i > j || i == j) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int diag = fruits[i][j] + solve(i + 1, j + 1, n, fruits,dp);
        int left = fruits[i][j] + solve(i + 1, j, n, fruits,dp);
        int bot = fruits[i][j] + solve(i + 1, j - 1, n, fruits,dp);

        return dp[i][j]=max({diag, left, bot});
    }
    int solve2(int i, int j, int n, vector<vector<int>>& fruits,vector<vector<int>>&dp) {
        if (i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        if (i < j || i == j) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int diag = fruits[i][j] + solve2(i - 1, j + 1, n, fruits,dp);
        int left = fruits[i][j] + solve2(i, j + 1, n, fruits,dp);
        int bot = fruits[i][j] + solve2(i + 1, j + 1, n, fruits,dp);
        return dp[i][j]=max({diag, left, bot});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int res = 0;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int c1=solve0(n,fruits);
        int c2 = solve(0, n - 1, n, fruits,dp);
        int c3 = solve2(n - 1, 0, n, fruits,dp);
        return c1 + c2 + c3;
    }
};
