class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Clear extra elements in nums1 beyond the valid portion
        for (int i = nums1.size() - 1; i >= m; i--) {
            nums1.pop_back();
        }

        // Add the valid elements from nums2 to nums1
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums2[i]);
        }

        // Sort nums1 to merge the two arrays
        sort(nums1.begin(), nums1.end());
    }
};
