class Solution {
public:
     vector<pair<int,int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
    // int bfs(int sr,int sc,vector<vector<int>>& mat , vector<vector<int>>&dist)
    // {
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     vector<vector<int>>vis(n,vector<int>(m,0));
        
    //     q.push({{sr,sc},0});
    //     int cnt=1;
    //     while(!q.empty())
    //     {
    //         int u=q.front().first.first;
    //         int v=q.front().first.second;
    //         int t=q.front().second;
    //         q.pop();
    //         cnt=max(cnt,t);
    //         for(auto [i,j] : dir)
    //         {
    //             int i_ = u+i;
    //             int j_ =v+j;
    //             if(i_>=0&&i_<n &&j_>=0&&j_<m&&vis[i_][j_]==0)
    //             {
    //                 if(mat[i_][j_]==0)
    //                 {
    //                     return t+1;
    //                 }
    //                 else
    //                 {
    //                     vis[i_][j_]=1;
    //                     q.push({{i_,j_},t+1});
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int u=q.front().first.first;
            int v=q.front().first.second;
            int t=q.front().second;
            dist[u][v]=t;
            q.pop();
            for(auto [i,j] : dir)
            {
                int i_=u+i;
                int j_=v+j;
                if(i_>=0&&i_<n &&j_>=0&&j_<m&&vis[i_][j_]==0)
                {
                    vis[i_][j_]=1;
                    q.push({{i_,j_},t+1});
                }
            }

        } 
        return dist;
    }
};