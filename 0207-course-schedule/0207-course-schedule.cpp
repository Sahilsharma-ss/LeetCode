class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto &i : prerequisites)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>sort;
        while(!q.empty())
        {
            int node=q.front();
            sort.push_back(node);
            q.pop();

            for(int i : adj[node])
            {
                indeg[i]--;
                if(indeg[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(sort.size()!=numCourses) return false;
        return true;
    }
};