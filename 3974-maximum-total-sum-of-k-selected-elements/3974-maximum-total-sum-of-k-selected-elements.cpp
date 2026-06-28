class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long res = 0;
        int ind = 0;
        while(k>0)
        {
            if(mul>0)
            {
                res += (long long)mul*nums[ind++];
                mul--;
            }
            else
            {
                res += nums[ind++];
            }
            k--;
        }
        return res;

    }
};