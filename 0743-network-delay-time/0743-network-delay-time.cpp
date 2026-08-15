class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i : times)
        {
            mp[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k] = 0;
       // vector<int>vis(n+1,0);
        while(!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(wt > dist[node]) continue; // ignore stale wt
            for(auto i : mp[node])
            {
                    if(wt+i.second < dist[i.first])
                    {
                        dist[i.first] = wt+i.second;
                        pq.push({wt+i.second,i.first});
                    }
            }
        }
        dist[0] = 0;
        int maxi = *max_element(dist.begin(),dist.end());
        return maxi==1e9?-1:maxi;
    }
};