class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &ok)
    {
        if(grid1[i][j] ==0 && grid2[i][j]==1 )
        {
            ok = false;
        }
        vis[i][j] = 1;
        for(auto [dx,dy] : dir)
        {
            int x = i+dx;
            int y = j+dy;

            if(x>=0 && y>=0 &&x<n && y<m && !vis[x][y] && grid2[x][y]==1)
            {
                dfs(x,y,vis,grid1,grid2,ok);
            } 
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,false));
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && !vis[i][j])
                {
                    bool ok = true;
                    dfs(i,j,vis,grid1,grid2,ok);
                    if(ok)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};