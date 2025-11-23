class Solution {
public:
    int n;

    int solve(int i, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) {
            return (rem == 0 ? 0 : -1000000000);
        }

        if (dp[i][rem] != -1)
            return dp[i][rem];
        // not take
        int not_take = solve(i + 1, rem, nums, dp);

        // take
        int newRem = (rem + nums[i] % 3) % 3;
        int take = nums[i] + solve(i + 1, newRem, nums, dp);

        return dp[i][rem] = max(take, not_take);
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(0, 0, nums, dp);
    }
};
