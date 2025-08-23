class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==0)
        {
            return nums[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int not_take=0+solve(ind-1,nums,dp);
        int take=-1e9;
        if(ind-2>=0) take=solve(ind-2,nums,dp)+nums[ind];
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};