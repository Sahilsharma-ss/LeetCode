class Solution {
public:
    int n;
    int solve(int i,int j,vector<int>& values,vector<vector<int>>&dp)
    {
        if(j-i<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1e8;
        for(int k=i+1;k<j;k++)
        {
            int ans= (values[i]*values[j]*values[k])+ solve(i,k,values,dp)  + solve(k,j,values,dp);
             res=min(res,ans);
        }
        return dp[i][j]=res;
    }
    int minScoreTriangulation(vector<int>& values) {
       n=values.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return solve(0,n-1,values,dp);
    }
};