class Solution {
public:
    bool iscycle(int node,unordered_map<int,vector<int>>&mp,vector<int>&vis,vector<int>&pathvis)
    {
        vis[node] = 1;
        pathvis[node] =1;
        for(auto i : mp[node])
        {
            if(!vis[i])
            {
                if(iscycle(i,mp,vis,pathvis)) return true; 
            }
            else
            {
               if(pathvis[i]==1)
               {
                    return true;
               }
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        for(auto i : prerequisites)
        {
            mp[i[1]].push_back(i[0]);
        }
        vector<int>vis(numCourses,0),pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]) continue;
            if(iscycle(i,mp,vis,pathvis))
            {
                return false;
            }
        }
        return true;
    }
};