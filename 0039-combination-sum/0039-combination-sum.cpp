class Solution {
public:
    void solve(int ind,int sum,int target,vector<vector<int>>&res,vector<int>curr,vector<int>nums)
    {
        if(ind==nums.size())
        {
            if(sum==target)
            {
                res.push_back(curr);
            }
            return;
        }
        int c=0;
        while(sum+nums[ind]<=target)
        {
            sum+=nums[ind];
            curr.push_back(nums[ind]);
            c++;
            solve(ind+1,sum,target,res,curr,nums);
        }
        while(c--)
        {
            sum-=nums[ind];
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