class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int p=flights[i][2];
            adj[u].push_back({v,p});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto &i : adj[node])
            {
                int v=i.first;
                int w=i.second;
                if(cost+w<dist[v]&&stops<=k)
                {
                    dist[v]=cost+w;
                    q.push({stops+1,{v,cost+w}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};