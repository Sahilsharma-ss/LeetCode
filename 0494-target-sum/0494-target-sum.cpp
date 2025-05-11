class Solution {
public:
    int findways(vector<int>& arr, int ind, int s, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (s == 0 && arr[0] == 0) return 2;
            if (s == 0 || s == arr[0]) return 1;
            return 0;
        }

        if (dp[ind][s] != -1) return dp[ind][s];

        int not_pick = findways(arr, ind - 1, s, dp);
        int pick = 0;
        if (arr[ind] <= s) {
            pick = findways(arr, ind - 1, s - arr[ind], dp);
        }

        return dp[ind][s] = not_pick + pick;
    }

    int countPartitions(vector<int>& arr, int d) {
        int tsum = 0;
        for (int num : arr) tsum += num;

        if (tsum - d < 0 || (tsum - d) % 2 != 0) return 0;

        int target = (tsum - d) / 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return findways(arr, n - 1, target, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};
