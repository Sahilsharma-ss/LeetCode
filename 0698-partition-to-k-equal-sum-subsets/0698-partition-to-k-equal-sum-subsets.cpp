class Solution {
public:
    int sz;
    vector<int>dp;
    bool solve(int mask ,int curr,int target,vector<int>&nums)
    {
        if(mask==sz)
        {
            return true;
        }
        if(curr==target)
        {
            curr = 0;
        }
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<nums.size();i++)
        {
            if(mask & (1<<i)) continue;
            int newmask = mask | (1<<i);
            if(curr+nums[i] <= target)
            {
               if(solve(newmask,curr+nums[i],target,nums))
               {
                return dp[mask] = true;
               }
            }
        }
        return dp[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        int target = sum/k;
        int mask = 0;
        sz = 1<<n;
        dp.resize(sz,-1);
        sz -=1;
        return solve(mask,0,target,nums);
    }
};