class Solution {
public:
    unordered_map<long long, int> dp[1005]; 
    // dp[ind][currSum] = no of ways

    int solve(int ind, int currSum, vector<int>& nums, int tar) {
        if (ind < 0) {
            return currSum == tar ? 1 : 0;
        }

        if (dp[ind].count(currSum)) return dp[ind][currSum];

        int left  = solve(ind - 1, currSum - nums[ind], nums, tar);
        int right = solve(ind - 1, currSum + nums[ind], nums, tar);

        return dp[ind][currSum] = left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size() - 1, 0, nums, target);
    }
};
