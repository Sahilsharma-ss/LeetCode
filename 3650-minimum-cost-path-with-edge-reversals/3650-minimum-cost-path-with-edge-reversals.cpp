class Solution {
public:
    void diji(int src,unordered_map<int,vector<pair<int,int>>>&mp,vector<int>&dist,vector<bool>&vis)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         dist[src] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;
            for(auto &p : mp[node])
            {
                int next = p.first;
                int cst = p.second;
                if( (dis+cst) < dist[next])
                {
                    dist[next] = dis+cst;
                    pq.push({dis+cst,next});
                }
            }
        }

    }
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i : edges)
        {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            mp[a].push_back({b,c});
            mp[b].push_back({a,(2*c)});
        }
        vector<int>dist(n,1e9);
        vector<bool>vis(n,false);
        diji(0,mp,dist,vis);
        for(auto i : dist)
        {
            cout<<i<<" ";
        }
        return dist[n-1]==-1e9?-1:dist[n-1];
    }
};