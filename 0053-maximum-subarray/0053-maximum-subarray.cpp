class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currs = 0;
        int maxs = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            currs += nums[i];
            if (currs > maxs) {
                maxs = currs;
            }
            if (currs < 0) {
                currs = 0;
            }
        }
        return maxs;
    }
};