class Solution {
public:
    int n;
    long long dp[1001][501][3];

    long long solve(int idx, int k, int type, vector<int>& prices) {
        if (k == 0) return 0; // no transactions left
        if (idx == n - 1) {
            // force close if holding something
            if (type == 0) return 0;                 // free → nothing to do
            else if (type == 1) return prices[idx];  // must sell to close long
            else return -prices[idx];                // must buy back to close short
        }

        if (dp[idx][k][type] != -1) return dp[idx][k][type];

        long long ans = 0;

        if (type == 0) {
            // Free: can start long, start short, or skip
            long long startLong  = -prices[idx] + solve(idx + 1, k, 1, prices);
            long long startShort =  prices[idx] + solve(idx + 1, k, 2, prices);
            long long skip       = solve(idx + 1, k, 0, prices);
            ans = max({startLong, startShort, skip});
        }
        else if (type == 1) {
            // Holding long: sell or skip
            long long sell = prices[idx] + solve(idx + 1, k - 1, 0, prices);
            long long hold = solve(idx + 1, k, 1, prices);
            ans = max(sell, hold);
        }
        else {
            // Holding short: buy back or skip
            long long buyBack = -prices[idx] + solve(idx + 1, k - 1, 0, prices);
            long long hold    = solve(idx + 1, k, 2, prices);
            ans = max(buyBack, hold);
        }

        return dp[idx][k][type] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, 0, prices); // start free with full capacity
    }
};
