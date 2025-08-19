class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                int start=i;
                int j=i;
                while(j<nums.size()&&nums[j]==0)
                {
                    j++;
                }
                long long k=j-i;
                ans+=(k*(k+1))/2;
                i=j-1;
            }
        }
        return ans;
    }
};