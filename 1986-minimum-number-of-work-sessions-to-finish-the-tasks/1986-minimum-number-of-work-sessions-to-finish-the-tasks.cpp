typedef long long ll;
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int x = sessionTime;
        int sz = 1<<n;
    vector<pair<ll,ll>>dp(sz,{1e9,1e9});
    dp[0] = {1,0};  // 0 mask no person in lift started 1 ride 0 wt
    for(int mask =0;mask<sz;mask++)
    {
        auto i = dp[mask];
        ll rides = i.first;
        ll lastwt = i.second;
        if(rides == 1e9) continue;
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i)) continue; // if already in mask continue
           int newmask = mask | (1<<i);  // include this person in ride
            pair<ll,ll>p;
            if(lastwt+tasks[i] <= x) // add in same ride
            {
                p = {rides,lastwt+tasks[i]};
            }
            else{ // another ride
                p = {rides+1,tasks[i]};
            }
            dp[newmask] = min(dp[newmask],p);
        }
    }
    int ans = sz-1; // all one;
    return dp[ans].first;
    }
};