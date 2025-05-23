class Solution {
public:

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int cnt=0;
        int mini=1e9;
        for(long long i : nums)
        {
            if((k^i)>i)
            {
                sum+=k^i;
                cnt++;
            }
            else
            {
                sum+=i;
                mini=min((long long)mini,abs(i-(i^k)));
            }
        }
        if(cnt%2==1)
        {
            sum=sum-mini;
        }
        return sum;
    }
};