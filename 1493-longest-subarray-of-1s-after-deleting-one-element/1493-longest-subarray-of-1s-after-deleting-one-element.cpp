class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int zeroes=0;
        int cnt=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                zeroes++;
            }
            while(l<n&&zeroes>1)
            {
                if(nums[l]==0)
                {
                    zeroes--;
                }
                l++;
            }
           if(zeroes<2)
           {
            cnt=max(cnt,r-l+1);
           }
            r++;
        }
        return cnt-1;
    }
};