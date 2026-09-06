class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s ,string &t)
    {
        if(j<0) return 1; // target consumed
        if(i<0) return 0; // source string finished 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j] = solve(i-1,j-1,s,t) + solve(i-1,j,s,t);// 1st move both indices 2nd keep target address at same pos and move s index to match other 
        }
        else
        {
            return dp[i][j] = solve(i-1,j,s,t); // move only source string 
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
       dp.resize(n,vector<int>(m,-1));
       return solve(n-1,m-1,s,t);
    }
};