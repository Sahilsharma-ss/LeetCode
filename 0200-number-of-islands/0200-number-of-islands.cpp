class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        if(vis[i][j]) return;
        vis[i][j] = 1;
        for(auto d : dir)
        {
            int i_ = i+d[0];
            int j_ = j+d[1];
            if(i_<n && i_>=0 && j_<m && j_>=0 && grid[i_][j_]=='1' && !vis[i_][j_])
            {
                solve(i_,j_,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m  = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    solve(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};