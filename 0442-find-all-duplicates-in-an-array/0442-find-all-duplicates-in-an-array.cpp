class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(size_t i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[i-1])
            {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};  