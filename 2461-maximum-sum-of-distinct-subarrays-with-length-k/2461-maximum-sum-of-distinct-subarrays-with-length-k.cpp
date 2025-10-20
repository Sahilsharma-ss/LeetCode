class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        long long sum=0;
        long long maxi=0;
        unordered_map<int,int>mp;
        while(r<n)
        {
            mp[nums[r]]++;
            sum+=nums[r];
            while(mp.size()>k || r-l+1>k)
            {
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1==k && mp.size()==k)
            {
                maxi = max(maxi,sum);
            }
            r++;
        }
        return maxi;
    }
};