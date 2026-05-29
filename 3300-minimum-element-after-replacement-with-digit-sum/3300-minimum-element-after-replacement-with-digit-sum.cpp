class Solution {
public:
    int minElement(vector<int>& nums) {
        int maxi = 1e9;
        for(int i=0;i<nums.size();i++)
        {
            int tmp = nums[i];
            int sum = 0;
            while(tmp>0)
            {
                sum+=tmp%10;
                tmp/=10;
            }
            if(sum<maxi)
            {
                maxi = sum;
            }
        }
        return maxi;
    }
};