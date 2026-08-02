class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                long long mul = 1ll*nums[i]*nums[j];
                long long g = pow(gcd(nums[i], nums[j]),2);
                if(mul/g > ans)
                {
                    ans = mul/g;
                }
            }
        }
        return ans;
    }
};