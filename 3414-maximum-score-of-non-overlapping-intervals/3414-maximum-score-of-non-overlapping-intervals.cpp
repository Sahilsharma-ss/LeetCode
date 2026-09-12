typedef long long ll;

class Solution {
public:
    int n;

    vector<vector<pair<ll,vector<int>>>> dp;
    vector<vector<int>> vis;

    int getNext(int ind, vector<vector<int>>& intervals)
    {
        int l = ind + 1;
        int r = n;

        while(l < r)
        {
            int mid = (l+r)/2;

            if(intervals[mid][0] > intervals[ind][1])
                r = mid;
            else
                l = mid+1;
        }

        return l;
    }

    pair<ll,vector<int>> solve(int ind, int cnt,
                               vector<vector<int>>& intervals)
    {
        if(ind==n || cnt==4)
            return {0,{}};

        if(vis[ind][cnt])
            return dp[ind][cnt];

        vis[ind][cnt] = 1;

        // not take
        auto res1 = solve(ind+1,cnt,intervals);

        pair<ll,vector<int>> not_take = {
            res1.first,
            res1.second
        };

        // take
        int nxt = getNext(ind,intervals);

        auto res = solve(nxt,cnt+1,intervals);

        pair<ll,vector<int>> take = {
            intervals[ind][2] + res.first,
            res.second
        };

        take.second.push_back(intervals[ind][3]);

        if(take.first > not_take.first)
        {
            return dp[ind][cnt] = take;
        }

        if(not_take.first > take.first)
        {
            return dp[ind][cnt] = not_take;
        }

        // same weight
        sort(take.second.begin(),take.second.end());
        sort(not_take.second.begin(),not_take.second.end());

        if(take.second < not_take.second)
        {
            return dp[ind][cnt] = take;
        }

        return dp[ind][cnt] = not_take;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals)
    {
        n = intervals.size();

        int ind = 0;

        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(ind++);
        }

        sort(intervals.begin(),intervals.end());

        dp.resize(n,vector<pair<ll,vector<int>>>(5));
        vis.resize(n,vector<int>(5,0));

        auto ans = solve(0,0,intervals);

        sort(ans.second.begin(),ans.second.end());

        return ans.second;
    }
};