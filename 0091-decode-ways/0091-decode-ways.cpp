class Solution {
public:
int n;
    int solve(string s,int i,vector<int>dp)
    {
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        ways +=solve(s,i+1,dp);
        if(i+1<n)
        {
            int two=((s[i]-'0')*10)+(s[i+1]-'0');
            if(two>=10&&two<=26)
            {
                ways+=solve(s,i+2,dp);
            }
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
         n= s.size();
        vector<int>dp(n,-1);
        int cnt=0;
        return solve(s,0,dp);
    }
};