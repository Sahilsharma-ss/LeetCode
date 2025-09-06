class Solution {
public:
    int solve(int ind,int tar,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(tar==0) return 0;
        if(ind==0) return (tar%coins[0]==0?tar/coins[0]:1e9);
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int not_take=0+solve(ind-1,tar,coins,dp);
        int take=1e9;
        if(coins[ind]<=tar)
        {
            take =1+solve(ind,tar-coins[ind],coins,dp);
        }
        return dp[ind][tar]= min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        return ans==1e9?-1:ans;
    }
};