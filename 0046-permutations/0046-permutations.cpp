class Solution {
private:
    void bt(vector<vector<int>>& ans, vector<int>& nums, int idx){
        if(idx == nums.size()) return ans.push_back(nums);
        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            bt(ans, nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        bt(ans, nums, 0);
        return ans;
    }
};