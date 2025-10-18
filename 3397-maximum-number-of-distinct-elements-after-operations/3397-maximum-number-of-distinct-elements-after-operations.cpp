class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int last = INT_MIN;

        for (int num : nums) {
            // We can choose the smallest possible number >= last + 1
            int val = max(num - k, last + 1);

            if (val <= num + k) {
                st.insert(val);
                last = val;
            }
        }
        return st.size();
    }
};
