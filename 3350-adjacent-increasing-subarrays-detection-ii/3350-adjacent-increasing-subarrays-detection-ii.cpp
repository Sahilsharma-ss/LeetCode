class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }

        right[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) right[i] = right[i+1] + 1;
            else right[i] = 1;
        }

        int maxi = 1;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, min(left[i-1], right[i]));
        }

        return maxi;
    }
};
