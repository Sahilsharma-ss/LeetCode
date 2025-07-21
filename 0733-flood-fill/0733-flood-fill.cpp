class Solution {
public:
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int sp=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            for(auto [i,j] : dir)
            {
                 int i_ = u+i;
                int j_ =v+j;
                if(i_>=0&&i_<n &&j_>=0&&j_<m)
                {
                    if(image[i_][j_]==sp&&vis[i_][j_]==0)
                    {
                        image[i_][j_]=color;
                        vis[i_][j_]=1;
                        q.push({i_,j_});
                    }
                }
            }
        }
        return image;
    }
};