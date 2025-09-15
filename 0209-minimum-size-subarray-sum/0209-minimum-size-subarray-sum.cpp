class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int mini=1e9;
        int sum=0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>target)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==target)
            {
                mini=min(mini,r-l+1);
            }
            r++;
        }
        return mini==1e9?0:mini;
    }
};