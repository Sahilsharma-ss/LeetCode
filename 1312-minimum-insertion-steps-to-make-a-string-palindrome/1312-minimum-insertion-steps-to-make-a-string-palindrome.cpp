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
    int minInsertions(string s) {
        string s1=s;
        int l1=s.size();
        int l2=l1;
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        reverse(s1.begin(),s1.end());
        return s.size()-lcs(l1-1,l2-1,s,s1,dp);
    }
};