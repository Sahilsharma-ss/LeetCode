class Solution {
public:
    int n;
    int ans = -1e9;
    vector<int>dp;
    int solve(int ind,vector<pair<pair<int,int>,int>>&vec,vector<int>&starts)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int nt = 0 + solve(ind+1,vec,starts);
        int next = lower_bound(starts.begin(),starts.end(),vec[ind].first.second)-starts.begin();
        int  take = vec[ind].second  + solve(next,vec,starts); 
        // cout<<max(nt,take);
        return  dp[ind] = max(nt,take);;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>vec;
        n = startTime.size();
        dp.resize(n+1,-1);
        for(int i=0;i<n;i++)
        {
            vec.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(vec.begin(),vec.end(),[&](auto &a, auto &b)
        {
            return a.first.first < b.first.first;
        });
        vector<int>starts;
        for(auto i : vec)
        {
            starts.push_back(i.first.first);
        }
        //reverse(vec.begin(),vec.end());
        return solve(0,vec,starts);
    }
};