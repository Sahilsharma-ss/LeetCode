class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        } 
        return parent[x] = find(parent[x]);
    }
    bool unite(int a ,int b)
    {
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return true;
        parent[pb] = pa;
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       // if(n-1>connections.size()) return -1;
        int con = 0;
        parent.resize(n,0);
        for(int i=0;i<n;i++)    
        {
            parent[i] = i;
        }
        for(auto i : connections)
        {
            int a  = i[0];
            int b = i[1];
            if(unite(a,b)) con++;
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(find(i)==i) components++;
        }
        int need = components-1;
        return (con>=need)?need:-1;
    }
};