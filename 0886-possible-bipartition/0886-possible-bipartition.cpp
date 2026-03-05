class Solution {
public:
bool isbipartite(int node,unordered_map<int,vector<int>>&adj,vector<int>&col,int currcol)
    {
        col[node] = currcol;
        for(int i : adj[node])
        {
            if(col[i]==-1)
            {
                if(!isbipartite(i,adj,col,1-currcol)) return false;
            }
           else if(col[node]==col[i])
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         unordered_map<int,vector<int>>adj;
        for(auto &i : dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>col(n+1,-1);
        for(int i=1;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!isbipartite(i,adj,col,0)) return false;
            }
        }
        return true;
    }
};