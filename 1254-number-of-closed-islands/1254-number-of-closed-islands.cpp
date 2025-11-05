class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid)
    {
        vis[i][j] = true;
        for(auto [dx,dy] : dir)
        {
            int x = i+dx;
            int y = j+dy;

            if(x>=0 && y>=0 &&x<n && y<m && !vis[x][y] && grid[x][y]==0)
            {
                dfs(x,y,vis,grid);
            } 
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 ||i==n-1 || j==m-1)
                {
                    if( grid[i][j]==0 && !vis[i][j])
                    {
                        dfs(i,j,vis,grid);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==0)
                {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};