class Solution {
public:
    int n;
    int solve(int ind,int buy,int cd,vector<int>& prices,vector<vector<vector<int>>>&dp) // cd->cooldown
    {

        if(ind>=n) return 0;
        if(cd==1)
        {
           return dp[ind][buy][cd] = solve(ind + 1, 1, 0, prices, dp);
        }
        if(dp[ind][buy][cd]!=-1) return dp[ind][buy][cd];
        if(buy&&cd==0)
        {
           return  dp[ind][buy][cd] = max(-prices[ind]+solve(ind+1,0,0,prices,dp),0+solve(ind+1,1,0,prices,dp));
        }
        else
        {
           return dp[ind][buy][cd]=max(prices[ind]+solve(ind+1,1,1,prices,dp),0+solve(ind+1,0,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0,prices,dp);
    }
};