class Solution {
public:
    int n,m;

    void dfs(int node , vector<int>&vis , unordered_map<int,vector<int>>&mp)
    {
        vis[node] = 1;
        for(auto i : mp[node])
        {
            if(!vis[i])
            {
                dfs(i,vis,mp);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        m=isConnected[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i =0 ;i<n ;i++)
        {
                if(!vis[i])
                {
                    dfs(i,vis,mp);
                    cnt++;
                }
        }
        return cnt;
    }
};