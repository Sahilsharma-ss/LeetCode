class Solution {
public:
    int n;
    long long mod = 1e9+7;
    vector<int> depth,parent;

    long long power(long long a,long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b&1)
            {
                ans = (ans*a)%mod;
            }
            a = (a*a)%mod;
            b>>=1;
        }
        return ans;
    }

    void dfs(int node ,unordered_map<int,vector<int>>&mp,int cnt,vector<int>&vis,int par)
    {
        if(vis[node]) return;

        vis[node] = 1;
        depth[node] = cnt;
        parent[node] = par;

        for(auto i : mp[node])
        {
            if(!vis[i])
            {
                dfs(i,mp,cnt+1,vis,node);
            }
        }
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {

        unordered_map<int,vector<int>> mp;
        n = 0;

        for(auto i : edges)
        {
            n = max({n,i[0],i[1]});
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        depth.resize(n+1,0);
        parent.resize(n+1,-1);

        vector<int> vis(n+1,0);

        dfs(1,mp,0,vis,-1);

        int cols = log2(n)+1;

        vector<vector<int>> up(n+1,vector<int>(cols,-1));

        for(int i=1;i<=n;i++)
        {
            up[i][0] = parent[i];
        }

        for(int j=1;j<cols;j++)
        {
            for(int node=1;node<=n;node++)
            {
                if(up[node][j-1]!=-1)
                {
                    up[node][j] = up[up[node][j-1]][j-1];
                }
            }
        }

        vector<int> res;

        for(auto i : queries)
        {
            int a = i[0];
            int b = i[1];

            int u = depth[a];
            int v = depth[b];

            if(u<v)
            {
                swap(a,b);
                swap(u,v);
            }

            int k = u-v;

            for(int j=0;j<cols;j++)
            {
                if(k&(1<<j))
                {
                    a = up[a][j];
                }
            }

            int lcanode;

            if(a==b)
            {
                lcanode = a;
            }
            else
            {
                for(int j=cols-1;j>=0;j--)
                {
                    if(up[a][j]==-1) continue;

                    if(up[a][j]!=up[b][j])
                    {
                        a = up[a][j];
                        b = up[b][j];
                    }
                }

                lcanode = parent[a];
            }

            int d = u + v - 2*depth[lcanode];

            if(d==0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(power(2,d-1));
            }
        }

        return res;
    }
};