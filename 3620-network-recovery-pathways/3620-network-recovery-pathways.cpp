class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> mp;
    vector<long long> dp;
    vector<int> vis;

    long long solve(int node, int mid, vector<bool> &online)
    {
        if(node == n - 1)
            return 0;

        if(vis[node])
            return dp[node];

        vis[node] = 1;
        dp[node] = 1e18;

        for(auto &i : mp[node])
        {
            int nxt = i.first;
            int cost = i.second;

            if(cost < mid)
                continue;

            if(nxt != n - 1 && !online[nxt])
                continue;

            dp[node] = min(dp[node], cost * 1LL + solve(nxt, mid, online));
        }

        return dp[node];
    }

    bool check(int mid, vector<bool> &online, long long k)
    {
        dp.assign(n, 0);
        vis.assign(n, 0);

        return solve(0, mid, online) <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k)
    {
        n = online.size();
        mp.assign(n, {});

        int hi = 0;

        for(auto &e : edges)
        {
            mp[e[0]].push_back({e[1], e[2]});
            hi = max(hi, e[2]);
        }

        int lo = 0;
        int ans = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if(check(mid, online, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};