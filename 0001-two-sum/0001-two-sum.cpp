class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int sum=0;
       int n=nums.size();
       int flag=0;
        vector<int>res;
       for(int i=0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                res.push_back(i);
                res.push_back(j);
                flag=1;
                break;
            }
            if(flag==1) break;
        }
       }
       return res;
    }
};