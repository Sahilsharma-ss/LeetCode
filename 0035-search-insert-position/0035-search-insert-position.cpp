class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            // while(arr[mid]<target)
            // {
            //     mid++;
            //     ans=mid+1;
            // }
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return r+1;
    }
};