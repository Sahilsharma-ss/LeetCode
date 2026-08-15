class Solution {
public:
    vector<int>parent;
    int findit(int a)
    {
        if(a==parent[a]) return a;
        return parent[a] = findit(parent[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int  maxi =0 ;
        for(auto i : edges)
        {
            maxi = max({maxi,i[0],i[1]});
        }
        int n= maxi;
        parent.resize(n+1);
        for(int i =1;i<=n;i++)
        {
            parent[i] = i;
        }
        for(auto i : edges)
        {
            int a = i[0];
            int b = i[1];
            int u = findit(a);
            int v = findit(b);
            if(u==v) return i;
            parent[v] = u;
        }
        return {};
    }
};