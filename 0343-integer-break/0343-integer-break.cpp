class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if(n==0) return 1;
        if (dp[n] != -1)
            return dp[n];

        int ans = 0;

        for (int j = 1; j < n; j++) {

            ans = max(ans,
                     max(j * (n - j),
                         j * solve(n - j)));
        }

        return dp[n] = ans;
    }

    int integerBreak(int n) {

        dp.assign(n + 1, -1);

        dp[1] = 1;

        return solve(n);
    }
};