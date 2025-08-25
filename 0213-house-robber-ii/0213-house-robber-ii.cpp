class Solution {
public:
    int solve2(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==0)
        {
            return nums[0];
        }
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+ solve2(ind-2,nums,dp);
        int n_take=0+solve2(ind-1,nums,dp);
        return dp[ind]=max(take,n_take);
    }
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==1)
        {
            return nums[ind];
        }
        if(ind<1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+ solve(ind-2,nums,dp);
        int n_take=0+solve(ind-1,nums,dp);
        return dp[ind]=max(take,n_take);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int n=nums.size();
        vector<int>dp(n+1,-1);
       int ans1= solve(n-1,nums,dp);
        vector<int>dp2(n+1,-1);
       int ans2=solve2(n-2,nums,dp2);
       return max(ans1,ans2);
    }
};