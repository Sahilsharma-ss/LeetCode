class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses,0);
        for(auto i : prerequisites)
        {
            mp[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        for(int i : indegree)
        {
            cout<<i<<" ";
        }
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(auto i : mp[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(res.size()!= numCourses) return {};
        return res;
    }
};