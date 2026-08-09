class Solution {
public:
    int n;
    vector<int> suff;
    int dp[101][101];
    int solve(int ind, int m, vector<int>& piles) {
        if (ind >= n) return 0;
        int ans = 0;
        if(dp[ind][m]!=-1) return dp[ind][m];
        for (int j = 1; j <= min(2 * m, n); j++) {
            int take = suff[ind]; // tot remaining
            int opp = solve(ind + j, max(m, j), piles);
            int myscore = take - opp;
            ans = max(ans, myscore);
        }
        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suff.assign(n, 0);
        suff[n - 1] = piles[n - 1];
        memset(dp,-1,sizeof(dp));
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + piles[i];
        }
        return solve(0, 1, piles);
    }
};