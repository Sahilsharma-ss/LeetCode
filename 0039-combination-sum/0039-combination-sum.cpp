class Solution {
public:
    void solve(int ind,int sum,int target,vector<vector<int>>&res,vector<int>curr,vector<int>nums)
    {
        if(ind==nums.size())
        {
            if(target==0)
            {
                res.push_back(curr);
            }
            return;
        }
        if(nums[ind]<=target)
        {
            curr.push_back(nums[ind]);
            solve(ind,sum,target-nums[ind],res,curr,nums);
            curr.pop_back();
        }
        solve(ind+1,sum,target,res,curr,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>res;
        vector<int>curr;
        solve(0,0,target,res,curr,candidates);
        return res;
    }
};