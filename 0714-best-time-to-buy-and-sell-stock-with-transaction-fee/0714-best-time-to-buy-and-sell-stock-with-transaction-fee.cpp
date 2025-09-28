class Solution {
public:
    int n;
      int solve(int ind,int buy,vector<vector<int>>&dp,vector<int>&prices,int fee)
    {
        if(ind>=n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]= max(-prices[ind]+solve(ind+1,0,dp,prices,fee),0+solve(ind+1,1,dp,prices,fee));
        }
        else
        {
            return dp[ind][buy]= max(prices[ind]-fee+solve(ind+1,1,dp,prices,fee),0+solve(ind+1,0,dp,prices,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,dp,prices,fee);
    }
};