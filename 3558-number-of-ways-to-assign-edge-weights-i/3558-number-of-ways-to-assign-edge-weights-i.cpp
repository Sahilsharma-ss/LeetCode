class Solution {
public:
    int mod = 1e9+7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        int m = -1e9;
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            m = max({m,i[0],i[1]});
        }
        queue<pair<int,int>>q;
        q.push({0,1});
        int maxi = -1e9;
        vector<int>vis(m+1,false);
        while(!q.empty())
        {
            auto &[lev,node] = q.front();
            vis[node] = true;
            maxi = max(maxi,lev);
            for(int i : adj[node])
            {
               if(!vis[i]) q.push({lev+1,i});
            }
            q.pop();
        }
        int ans = 1;
        for(int i=1;i<maxi;i++)
        {
            ans  = (ans*2) % mod;
        }
        return ans;
    }
};