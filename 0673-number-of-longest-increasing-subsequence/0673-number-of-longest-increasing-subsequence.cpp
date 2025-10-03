class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>vec(n,1);
        for(int i=0;i<n;i++)
        {
            for(int p=0;p<i;p++)
            {
                    if(nums[p]<nums[i]&&dp[p]+1>dp[i])
                    {
                        dp[i]=dp[p]+1;
                        vec[i]=vec[p];
                    }
                    else if(nums[p]<nums[i]&&dp[i]==dp[p]+1)
                    {
                        vec[i]+=vec[p];
                    }
            }
        }
        int maxi = *max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                 ans+=vec[i];
            }
        }
        return ans;

    }
};