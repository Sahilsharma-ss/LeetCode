class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int c = 0;
        for (auto i : nums) {
            if (i == 0) {
                c++;
            }
            else
            {
                ans.push_back(i);
            }
        }
        for (int i = 0; i < c; i++) {
            ans.push_back(0);
        }
        return ans;
    }
};