class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res;
        vector<int>v(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]=nums[i];
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0) res=i;
        }
        return res;
    }
};