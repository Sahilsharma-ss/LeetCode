class Solution {
public:
    long long mod = 1e9 + 7;

    vector<vector<long long>> dp;
    vector<vector<long long>> pref;

    long long solve(long long ind, long long k, long long n, long long req) {
        if (k == req)
            return 1;

        if (ind >= n)
            return 0;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        long long not_take = solve(ind + 1, k, n, req);

        // Sum of:
        // dp[ind+1][k+1] ... dp[n-1][k+1]
        long long take = getSum(ind + 1, k + 1, n, req);

        return dp[ind][k] = (not_take + take) % mod;
    }

    long long getSum(long long ind, long long k, long long n, long long req) {
        if (ind >= n)
            return 0;

        if (pref[ind][k] != -1)
            return pref[ind][k];

        return pref[ind][k] =
                   (solve(ind, k, n, req) + getSum(ind + 1, k, n, req)) % mod;
    }

    int numberOfSets(long long n, long long k) {
        dp.assign(n + 1, vector<long long>(k + 1, -1));

        pref.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(0, 0, n, k);
    }
};