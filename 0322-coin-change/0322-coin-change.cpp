class Solution {
public:
    int f(int ind,int T,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(T%coins[0]==0) return T/coins[0];
            return 1e9;
        }
        if(dp[ind][T]!=-1) return dp[ind][T];
        int not_take=0+f(ind-1,T,coins,dp);
        int take=1e9;
        if(coins[ind]<=T)
        {
            take=1+f(ind,T-coins[ind],coins,dp);
        }
        return dp[ind][T]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int res=f(n-1,amount,coins,dp);
       if(res==1e9) return -1;
       return res;
    }
};