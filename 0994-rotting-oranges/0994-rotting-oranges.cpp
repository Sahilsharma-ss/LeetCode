class Solution {
public:
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                   q.push({{i,j},0});
                   vis[i][j]=1;
                }
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int u=q.front().first.first;
            int v=q.front().first.second;
            int t=q.front().second;
            q.pop();
            cnt=max(cnt,t);
            for(auto [i,j] : dir)
            {
                int i_ = u+i;
                int j_ =v+j;
                if(i_>=0&&i_<n &&j_>=0&&j_<m)
                {
                    if(vis[i_][j_]!=2 && grid[i_][j_]==1)
                    {
                        vis[i_][j_]=2;
                        q.push({{i_,j_},t+1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return cnt;
    }
};