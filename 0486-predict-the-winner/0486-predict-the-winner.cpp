typedef long long ll;
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int g =0;g<n;g++)
        {
            for(int i=0,j=g;j<n;++i,++j)
            {
                if(g==0)
                {
                    dp[i][j] = nums[i];
                }
                else if(g==1)
                {
                    dp[i][j] = max(nums[i],nums[j]);
                }else
                {
                    ll val1 = nums[i] + min(dp[i+1][j-1],dp[i+2][j]);
                    ll val2 = nums[j] + min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j] = max(val1,val2);
                }
            }
        }

            int sc = dp[0][n-1];
            int sum = accumulate(nums.begin(),nums.end(),0);
            int sc2 = sum-sc;
            if(sc>=sc2)
            {
                return true;
            }
         return false;
    }
};