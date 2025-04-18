class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>empty;
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
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
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
        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses) return empty;
        return ans;
    }
};