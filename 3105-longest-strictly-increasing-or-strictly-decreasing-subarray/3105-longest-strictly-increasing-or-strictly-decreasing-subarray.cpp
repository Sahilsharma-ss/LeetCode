class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int largestinc = 1, largestdec = 1;  // Minimum length is 1
        int inc = 1, dec = 1;  
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                largestinc = max(largestinc, inc);
            } else {
                inc = 1;  // Reset if not increasing
            }
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                dec++;
                largestdec = max(largestdec, dec);
            } else {
                dec = 1;  // Reset if not decreasing
            }
        }

        return max(largestinc, largestdec);
    }
};
