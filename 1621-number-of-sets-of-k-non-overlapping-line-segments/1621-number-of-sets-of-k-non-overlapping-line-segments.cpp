class Solution {
public:
    long long mod = 1e9 + 7;

    vector<vector<long long>> dp;
    vector<vector<long long>> sum;

    int numberOfSets(long long n, long long k) {
        dp.resize(n + 1, vector<long long>(k + 1, 0));
        sum.resize(n + 1, vector<long long>(k + 1, 0));

        // Base case:
        // if(k == req) return 1;
        for (long long ind = 0; ind <= n; ind++) {
            dp[ind][k] = 1;
        }

        // sum[ind][k] =
        // dp[ind][k] + dp[ind+1][k] + ...
        for (long long ind = n - 1; ind >= 0; ind--) {
            sum[ind][k] = (dp[ind][k] + sum[ind + 1][k]) % mod;
        }

        for (long long cnt = k - 1; cnt >= 0; cnt--) {
            for (long long ind = n - 1; ind >= 0; ind--) {
                long long not_take = dp[ind + 1][cnt];

                long long take = sum[ind + 1][cnt + 1];

                dp[ind][cnt] = (not_take + take) % mod;

                sum[ind][cnt] = (dp[ind][cnt] + sum[ind + 1][cnt]) % mod;
            }
        }

        return dp[0][0];
    }
};