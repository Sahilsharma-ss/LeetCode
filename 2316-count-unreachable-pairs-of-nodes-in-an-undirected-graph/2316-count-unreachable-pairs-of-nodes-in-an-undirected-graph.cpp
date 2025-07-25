class Solution {
public:
     vector<int>parent;
    vector<int>rank;
    
    int find(int x)
    {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p) return;
        if(x_p>y_p)
        {
            parent[y_p]=x_p;
        }
        else if(x_p<y_p)
        {
            parent[x_p]=y_p;
        }
        else
        {
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(auto &i : edges)
        {
            int x=find(i[0]);
            int y=find(i[1]);
            if(x!=y)
            {
                Union(x,y);
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[find(i)]++;
        }
        long long result=0;
        for(auto &i : mp)
        {
            result+=i.second*(n-i.second);
            n=n-i.second;
        }
        return result;
    }
};