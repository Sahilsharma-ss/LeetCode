class Solution {
public:
    int solve(vector<int>& nums, int tar, vector<int>& dp) {
        if (tar == 0) return 1;       
        if (dp[tar] != -1) return dp[tar];

        long long ways = 0;
        for (int num : nums) {
            if (num <= tar) {
                ways += solve(nums, tar - num, dp);
            }
        }
        return dp[tar] = (int)ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};
