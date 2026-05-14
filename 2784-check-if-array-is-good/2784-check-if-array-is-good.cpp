class Solution {
public:
    bool isGood(vector<int>& nums) {
        int base = nums.size() - 1;
        vector<int> vec;
        for (int i = 1; i <= base; i++) {
            vec.push_back(i);
        }
        vec.push_back(base);
        sort(nums.begin(), nums.end());
        return vec == nums;
    }
};