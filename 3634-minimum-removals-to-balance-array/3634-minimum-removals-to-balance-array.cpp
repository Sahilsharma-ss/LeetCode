class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int l=0;
        for(int i=0;i<nums.size();i++)
            {
                while(nums[i]>1ll*nums[l]*k)
                    {
                        l++;
                    }
                ans=max(ans,i-l+1);
            }
        return nums.size()-ans;
    }
};