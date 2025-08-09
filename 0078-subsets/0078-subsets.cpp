class Solution {
public:
    void generateall(int ind,vector<int>&nums,vector<int>&curr,vector<vector<int>>&res)
    {
        if(ind==nums.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        generateall(ind+1,nums,curr,res);
        curr.pop_back();
        generateall(ind+1,nums,curr,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        generateall(0,nums,curr,res);
        return res;
    }
};