class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m, m1;
        for (int i : nums) {
            m[i]++;
        }
        for (auto i : m) {
            m1[i.second]++;
        }
        for (int i = 0; i < n; i++) {
            if (m1[m[nums[i]]] == 1)
                return nums[i];
        }

        return -1;
    }
};