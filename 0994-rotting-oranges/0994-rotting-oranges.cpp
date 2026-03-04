class Solution {
public:
    vector<vector<int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
            }
        }
        int min = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt =0;
        while(!q.empty())
        {
            int i = q.front().second.first;
            int j = q.front().second.second;
            min = q.front().first;
            grid[i][j] =2;
            q.pop();
            for(auto &d : dir)
            {
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<n && i_>=0 && j_>=0 && j_<m && !vis[i_][j_] && grid[i_][j_]==1)
                {
                    int currt = min+1;
                    q.push({currt,{i_,j_}});
                    grid[i_][j_] = 2;
                }
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return min;
    }
};