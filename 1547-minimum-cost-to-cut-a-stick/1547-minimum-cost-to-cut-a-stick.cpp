class Solution {
public:
    int len ;
    int solve(int i ,int j,vector<int>& cuts,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        for(int k = i;k<=j;k++)
        {
            int curr  =  cuts[j+1] - cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp);
            ans = min(ans,curr);
        }
       return  dp[i][j] =ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        len = n;
        int sz = cuts.size();
        vector<vector<int>>dp(sz,vector<int>(sz,-1));
        return solve(1,sz-2,cuts,dp);
    }
};