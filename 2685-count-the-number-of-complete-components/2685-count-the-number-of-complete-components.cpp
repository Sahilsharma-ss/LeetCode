class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis,int &n,int &cnt)
    {
        if(vis[node]) return;
        if(!vis[node])
        {
            n++;
            vis[node]=true;
        }
        cnt= cnt+adj[node].size();
        for(auto i : adj[node])
        {
           if(!vis[i])
           {
            dfs(i,adj,vis,n,cnt);
           } 
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
    //     sort(edges.begin(),edges.end());
    //     unordered_map<int,int>mp;
    //     for(int i =0;i<n;i++)
    //     {
    //         mp[i] = i;
    //     }
    //     vector<int>cnt(n,0);
    //     for(auto i : edges)
    //     {
    //         int a = i[0];
    //         int b = i[1];
    //         mp[b] = mp[a];
    //         cnt[mp[a]]++;
    //     }
    //     unordered_set<int>st;
    //     // for(auto i : cnt)
    //     // {
    //     //     cout<<i<<" ";
    //     // }
    //    // cout<<endl;
    //     unordered_map<int,int>no;
    //     for(auto i : mp)
    //     {
    //        no[i.second]++;
    //     }
    //     int ans = 0;
    //     for(auto i : no)
    //     {
    //        // cout<<i.first<<" "<<i.second<<endl;
    //         int edge = i.second;
    //        // cout<<i.second<<" "<<((edge*(edge-1))/2)<<endl;
    //         if( cnt[i.first] == ((edge*(edge-1))/2))
    //         {
    //             ans++;
    //         }
    //     }
    //     return ans;
    unordered_map<int,vector<int>>mp;
    int ans = 0;
    for(auto i : edges)
    {
        int a= i[0];
        int b = i[1];
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
        vector<int>vis(n,false);
        for(int i =0;i<n;i++)
        {
            if(!vis[i])
            {
                int node = 0;
                int cnt = 0;
                dfs(i,mp,vis,node,cnt);
                cnt/=2;
                if(cnt ==((node*(node-1))/2))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};