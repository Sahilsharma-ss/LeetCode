class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int &sum,bool &reached)
    {
        if(i==0 || j==0 || i==n-1 || j==m-1)
        {
            reached = true;
        }
        sum+=grid[i][j];
        vis[i][j]=1;
        for(auto [dx,dy] : dir)
        {
            int x=i+dx;
            int y=j+dy;
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && !vis[x][y])
            {
                dfs(x,y,grid,vis,sum,reached);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=0;
        int total_one=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    total_one+=1;
                }
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int sum =0;
                    bool reached = false;
                    dfs(i,j,grid,vis,sum,reached);
                    if(reached)
                    {
                        res+=sum;
                    }
                }
            }
        }
        return total_one - res;
    }
};