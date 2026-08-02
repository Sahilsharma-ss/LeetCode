class Solution {
public:
    int sz;
    vector<vector<int>>dp;
    int mod = 1e9+7;
    int solve(int mask,int last,vector<int>&nums)
    {
        if(mask==sz)
        {
            return 1;
        }
        if(last !=-1 && dp[mask][last]!=-1) return dp[mask][last];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(mask & (1<<i)) continue;
            int newmask = mask | (1<<i);
            if(last==-1 || nums[last]%nums[i]==0 || nums[i]%nums[last]==0)
            {
                ans  = (ans + solve(newmask,i,nums))%mod;
            }
        }
        if(last != -1) dp[mask][last] = ans;
        return ans;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        sz = 1<<n;
        dp.resize(sz+1,vector<int>(n+1,-1));
        sz-=1;
        return solve(0,-1,nums);
    }
};