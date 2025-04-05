class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum|nums[i];
        }
        int n=pow(2,nums.size()-1);
        return n*sum;
    }
};