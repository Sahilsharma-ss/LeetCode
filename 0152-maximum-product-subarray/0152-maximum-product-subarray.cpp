class Solution {
public:

    vector<pair<long long,long long>> dp;
    vector<int> nums;
    vector<int> vis;

    pair<long long,long long> solve(int i)
    {
        if(i==0)
            return {nums[0], nums[0]};

        if(vis[i])
            return dp[i];

        auto [mx,mn] = solve(i-1);

        long long x = nums[i];

        long long curMax = max({
            x,
            x * mx,
            x * mn
        });

        long long curMin = min({
            x,
            x * mx,
            x * mn
        });

        vis[i] = 1;
        return dp[i] = {curMax, curMin};
    }

    int maxProduct(vector<int>& arr)
    {
        nums = arr;

        int n = nums.size();

        dp.resize(n);
        vis.assign(n,0);

        long long ans = nums[0];

        for(int i=0;i<n;i++)
        {
            auto [mx,mn] = solve(i);
            ans = max(ans,mx);
        }

        return ans;
    }
};