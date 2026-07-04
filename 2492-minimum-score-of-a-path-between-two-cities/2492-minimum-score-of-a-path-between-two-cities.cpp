class Solution {
public:
    int dfs(int node , unordered_map<int,vector<pair<int,int>>>&mp,vector<int>&vis,int sz)
    {
        queue<pair<int,int>>q;
        q.push({1e9,node});
        int mini = 1e9;
        bool ok = false;
        while(!q.empty())
        {
            int val = q.front().first;
            int n = q.front().second;
            if(n==sz)
            {
                ok = true;
                mini = min(mini,val);
            }
            if(vis[n])
            {
                q.pop();
                continue;
            }
            vis[n] = 1;
            q.pop();
            for(auto &i : mp[n])
            {
                mini = min(mini,i.second);
                if(!vis[i.first])
                {
                    q.push({min(val,i.second),i.first});
                }
            }
        }
        if(ok)
        {
            return mini;
        }
        return 1e9;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i : roads)
        {
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        vector<int>vis(n+1,0);
        int ans = 1e9;
        for(int i = 1;i<=n;i++)
        {
            int mini = 1e9;
            if(!vis[i]) 
            {
                mini = dfs(i,mp,vis,n);
            }
            ans = min(ans,mini);
        }
        return ans;
    }
};