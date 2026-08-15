class Solution {
public:
    vector<int>dp;
    int solve(int ind,vector<int>&nums)
    {
        if(ind<0)
        {
            return 0;
        }
        if(ind==0)
        {
            return nums[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int one = nums[ind] + solve(ind-2,nums);
        int not_take = solve(ind-1,nums);
        return dp[ind] = max(one,not_take);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        dp.resize(n+1,-1);
        return solve(n-1,nums);
    }
};