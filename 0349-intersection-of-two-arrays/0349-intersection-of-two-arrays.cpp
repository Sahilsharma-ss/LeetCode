class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()); // Store unique elements from nums1
        set<int> resultSet; // Store the intersection in a set (to avoid duplicates)

        for (int num : nums2) {
            if (set1.count(num)) { // Check if num exists in set1
                resultSet.insert(num);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end()); // Convert set to vector
    }
};

    