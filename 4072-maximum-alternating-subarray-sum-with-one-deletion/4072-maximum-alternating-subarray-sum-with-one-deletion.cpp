typedef long long ll;
class Solution {
public:
    ll inf = 1e18;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>add(n,vector<ll>(2,-inf));
        vector<vector<ll>>sub(n,vector<ll>(2,-inf));

        add[0][0] = nums[0];
        ll ans = nums[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                add[i][j] = max(1ll*nums[i], sub[i-1][j] + nums[i]);
                sub[i][j] = add[i-1][j] - nums[i];
            }
            // del i-1th ele
            if(i>1)
            {
                add[i][1] = max(add[i][1],sub[i-2][0] + nums[i]);
                sub[i][1] = max(sub[i][1],add[i-2][0] - nums[i]);
            }
            ans = max({ans,add[i][0],sub[i][0],add[i][1],sub[i][1]});
        }
        return ans;
    }
};