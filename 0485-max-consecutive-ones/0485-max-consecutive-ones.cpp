class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0;
        int curr1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                curr1 +=1;
                max1=max(max1,curr1);
            }
            else
            {
                curr1=0;
            }
        }
        return max1;
    }
};