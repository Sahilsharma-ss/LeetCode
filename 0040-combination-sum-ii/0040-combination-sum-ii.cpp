class Solution {
public:
    void generateallsubsequence(int ind, int sum, vector<int>& nums, vector<int>& curr,vector<vector<int>>& res, int target)
    {
        if (ind == nums.size()) {
            if (sum == target) {
                vector<int> sortedCurr = curr; 
                sort(sortedCurr.begin(), sortedCurr.end());
                res.push_back(sortedCurr);
            }
            return;
        }
        sum += nums[ind];
        curr.push_back(nums[ind]);
        generateallsubsequence(ind + 1, sum, nums, curr, res, target);

        curr.pop_back();
        sum -= nums[ind];
        generateallsubsequence(ind + 1, sum, nums, curr, res, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        generateallsubsequence(0, 0, candidates, curr, res, target);

        set<vector<int>> uniqueRes(res.begin(), res.end());
        return vector<vector<int>>(uniqueRes.begin(), uniqueRes.end());
    }
};
