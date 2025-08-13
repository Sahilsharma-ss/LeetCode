class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& curr,
            vector<vector<int>>& res) {
        res.push_back(curr);

        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res1;
        vector<int> curr;
        solve(0, nums, curr, res1);
        return res1;
    }
};