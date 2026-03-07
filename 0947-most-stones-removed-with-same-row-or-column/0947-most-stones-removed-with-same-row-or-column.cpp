class Dsu {
public:
    vector<int> parent, size;
    Dsu(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    int unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return true;
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
        } else if (size[pb] < size[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            size[pa]++;
        }
        return false;
    }
};
 class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    { 
        int n = stones.size();
        Dsu dsu(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    dsu.unite(i,j);
                }
            }
        }
        //  for(int i=0;i<n;i++)
        // {
        //    cout<<dsu.find(i)<<" ";
        // }
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(dsu.find(i));
        }
        return n-st.size();
    }
};