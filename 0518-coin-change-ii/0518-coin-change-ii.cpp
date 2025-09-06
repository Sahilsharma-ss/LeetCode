class Solution {
public:
    int solve(int ind,int tar,vector<vector<int>>&dp,vector<int>& coins)
    {
        if(tar==0) return 1;
        if(ind==0) return(tar%coins[0]==0?1:0);
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int not_take=0+solve(ind-1,tar,dp,coins);
        int take=0;
        if(coins[ind]<=tar)
        {
            take=solve(ind,tar-coins[ind],dp,coins);
        }
        return dp[ind][tar]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
};