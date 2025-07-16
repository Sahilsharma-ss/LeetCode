class Solution {
public:
    int solve(vector<int>&nums,int g)
    {
        if(g<0) return 0;
        int n=nums.size();
        int l=0,r=0,cnt=0,sum=0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>g)
            {
                sum-=nums[l];
                l++;
            }
            if(sum<=g)
            {
                cnt+=r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};