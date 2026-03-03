class Solution {
public:
    bool isdc(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis,vector<int>&pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto i : adj[node])
        {
            if(!vis[i]){
                if(isdc(i,adj,vis,pathvis)) return true;
            }
            else if(pathvis[i])
            {
                return true;
            }
        }
        pathvis[node] =0;
        return false;
    }
    void order(int node,stack<int>&stk,unordered_map<int,vector<int>>&adj,vector<int>&vis)
    {
        vis[node] = 1;
        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                order(i,stk,adj,vis);
            }
        }
        stk.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int>stk;
        unordered_map<int,vector<int>>adj;
        for(auto i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis1(numCourses,0),pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(isdc(i,adj,vis1,pathvis)) return {};
        }
      //  if(isdc(i,stk,adj,vis))
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                order(i,stk,adj,vis);
            }
        }
        vector<int>ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
    //    reverse(ans.begin(),ans.end());
        return ans;
    }
};