class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv=0;
        for(auto i : nums) maxv =max(maxv,i);
        int i=0;
        while(nums[i]!=maxv)
        {
            i++;
        }
        int cnt=0;
        while(i<nums.size()&&nums[i]==maxv)
        {
            cnt++;
            i++;
        }
        return cnt;
    }
};