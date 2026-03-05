class Solution {
public:
    bool isbipartite(int node,unordered_map<int,vector<int>>&adj,vector<int>&col,int currcol)
    {
        col[node] = currcol;
        for(auto i : adj[node])
        {
            if(col[node]==col[i])
            {
                return false;
            }
            if(col[i]==-1)
            {
                if(!isbipartite(i,adj,col,1-currcol)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<graph.size();i++)
        {
            adj[i] = graph[i];
        }
        int v = graph.size();
        vector<int>col(v,-1);
        for(int i=0;i<v;i++)
        {
            if(col[i]==-1)
            {
                if(!isbipartite(i,adj,col,0)) return false;
            }
        }
        return true;
    }
};