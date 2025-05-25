class Solution {
public:
int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = max(lcs(i - 1, j, s1, s2, dp), lcs(i, j - 1, s1, s2, dp));
}
    int longestPalindromeSubseq(string s) {
        int l1=s.length();
        int l2=l1;
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
      string s1(s.begin(),s.end());
      reverse(s1.begin(),s1.end());
    // Get the length of LCS
    return  lcs(l1 - 1, l2 - 1, s, s1, dp);
    }
};