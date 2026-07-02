class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
       priority_queue<pair<int,pair<int,int>>>pq;
        if(grid[0][0]==1)
        {
            health-=1;
        }
        pq.push({health,{0,0}});
        vector<vector<int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty())
        {
            int h = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            if(vis[i][j]) 
            {
                pq.pop();
                continue;
            }
            vis[i][j] = 1;
            pq.pop();
            if(i==n-1 && j==m-1 && h>=1)
            {
                return true;
            }
            for(auto d : dir)
            {
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<0 || j_<0 ||i_>n-1 || j_>m-1 || vis[i_][j_])
                {
                    continue;
                }
                int s = h;
                if(grid[i_][j_]==1)
                {
                    s = h-1;
                }
                if(s==0) continue;
                pq.push({s,{i_,j_}});
            }
        }
        return false;
    }
};