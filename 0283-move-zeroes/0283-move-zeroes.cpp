class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i =0 ; i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                nums.push_back(nums[i]);
               nums.erase(nums.begin()+i);

            }
        }
    }
};