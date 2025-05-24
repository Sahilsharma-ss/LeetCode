class Solution {
public:
    int solve(int l1, int l2, string& w1, string& w2, vector<vector<int>>& dp) {
        if (l1 < 0 || l2 < 0) return 0;
        if (dp[l1][l2] != -1) return dp[l1][l2];

        if (w1[l1] == w2[l2])
            return dp[l1][l2] = 1 + solve(l1 - 1, l2 - 1, w1, w2, dp);
        else
            return dp[l1][l2] = max(solve(l1 - 1, l2, w1, w2, dp), solve(l1, l2 - 1, w1, w2, dp));
    }

    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        int lcs = solve(l1 - 1, l2 - 1, word1, word2, dp);
        return (l1-lcs)+(l2-lcs);//delete all character that are not in l1+same for l2
    }
};
