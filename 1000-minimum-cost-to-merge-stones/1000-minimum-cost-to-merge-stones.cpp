class Solution {
public:
    int n, K;
    vector<int> pref;

    int dp[31][31][31];

    int rangeSum(int l, int r) {
        return pref[r + 1] - pref[l];
    }

    int solve(int i, int j, int piles) {

        if ((j - i + 1 - piles) % (K - 1))
            return 1e9;

        if (i == j)
            return (piles == 1 ? 0 : 1e9);

        if (dp[i][j][piles] != -1)
            return dp[i][j][piles];

        int ans = 1e9;

        if (piles == 1) {

            ans = solve(i, j, K);

            if (ans != 1e9)
                ans += rangeSum(i, j);
        }
        else {

            for (int mid = i; mid < j; mid += K - 1) {

                ans = min(
                    ans,
                    solve(i, mid, 1) +
                    solve(mid + 1, j, piles - 1)
                );
            }
        }

        return dp[i][j][piles] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {

        n = stones.size();
        K = k;

        if ((n - 1) % (K - 1))
            return -1;

        pref.resize(n + 1);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stones[i];

        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, 1);
    }
};