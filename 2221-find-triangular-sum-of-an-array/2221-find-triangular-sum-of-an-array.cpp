class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=1)
        {
            vector<int>temp(nums.size()-1);
            for(int i=1;i<nums.size();i++)
            {
                int no =nums[i-1]+nums[i];
                if(no<9)
                {
                    temp[i-1]=no;
                }
                else
                {
                    temp[i-1]=no%10;
                }
            }
            nums=temp;
        }
        return nums[0];
    }
};