class Solution {
public:
    int lcs(int ind1,int ind2,vector<vector<int>>&dp,string &s1,string &s2)
    {
        if(ind1<0||ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
        {
            return 1+lcs(ind1-1,ind2-1,dp,s1,s2);
        }
        return dp[ind1][ind2]=max(lcs(ind1-1,ind2,dp,s1,s2),lcs(ind1,ind2-1,dp,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return lcs(n-1,m-1,dp,text1,text2);
    }
};