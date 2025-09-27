class Solution {
public:
    int n;
    int solve(int ind,int buy,int cap,vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        if(cap<0) return 0;
        if(ind==n) return 0;

        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy)
        {
            return dp[ind][buy][cap]= max(-prices[ind]+solve(ind+1,0,cap,dp,prices),0+solve(ind+1,1,cap,dp,prices));
        }
        else
        {
            return dp[ind][buy][cap]= max(prices[ind]+solve(ind+1,1,cap-1,dp,prices),0+solve(ind+1,0,cap,dp,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,1,dp,prices);
    }
};