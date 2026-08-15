class Solution {
public:
    bool solve(int node ,vector<vector<int>>& graph, vector<int>&col,int currcol)
    {
        col[node] = currcol;
        for(auto i : graph[node])
        {
            if(col[i]==col[node])
            {
                return false;
            }
            if(col[i]==-1)
            {
                if(!solve(i,graph,col,1-currcol))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
       for(int i = 0; i < n; i++)
        {
            if(col[i] == -1)
            {
                if(!solve(i, graph, col, 0))
                    return false;
            }
        }
        return true;
    }
};