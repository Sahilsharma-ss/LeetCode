class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0 || nums[i]>n )
            {
                nums[i]=n+1;
            }
        }
        for(int i =0;i<n;i++)
        {
           int val = abs(nums[i]);
            if (val >= 1 && val <= n && nums[val - 1] > 0) {
                nums[val - 1] = -nums[val - 1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};