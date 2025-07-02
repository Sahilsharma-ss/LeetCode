class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>dir{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0 || grid[0][0]!=0)
        {
            return -1;
        }
        auto issafe = [&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n;
        };

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            int di=pq.top().first;
            pair<int,int>node=pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();

            for(auto d : dir)
            {
                int x_ =x+d[0];
                int y_ =y+d[1];
                int dista=1;
                if(issafe(x_,y_) && grid[x_][y_]==0 && di + dista < dist[x_][y_])
                { 
                    dist[x_][y_]=di+dista;
                    pq.push({di+dista,{x_,y_}});

                }
            }
        }
        if(dist[m-1][n-1]==INT_MAX) return -1;

        return dist[m-1][n-1]+1;
    }
};