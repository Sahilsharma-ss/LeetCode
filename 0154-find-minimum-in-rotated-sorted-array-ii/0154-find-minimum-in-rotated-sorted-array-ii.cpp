class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r = nums.size()-1;
        while(l<r)
        {
            while(l<r && nums[l+1]==nums[l])
            {
                l++;
            }
            while(l<r && nums[r-1]==nums[r])
            {
                r--;
            }
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return nums[r];
    }
};