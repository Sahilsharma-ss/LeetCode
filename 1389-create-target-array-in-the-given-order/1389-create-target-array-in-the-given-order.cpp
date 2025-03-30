class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int>target(n);
        for(int i=0;i<nums.size();i++)
        {
            target.insert(target.begin()+index[i],nums[i]);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=target[i];
        }
        return res;
    }
};