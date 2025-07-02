class Solution {
public:
    const int inf=1e9;
    typedef pair<int,pair<int,int>>P;
 vector<vector<int>>dir{{-1,0}, {1,0}, {0,-1}, {0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,vector<int>(n,inf));
        auto issafe=[&](int x,int y){
        return x<m && x>=0 && y>=0&&y<n;
    };
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            int d=pq.top().first;
            pair<int,int>node=pq.top().second;
            pq.pop();
            int x=node.first;
            int y=node.second;
            if (x == m - 1 && y == n - 1) return d;
            for(auto di : dir)
            {
                int x_=x+di[0];
                int y_=y+di[1];
                if(issafe(x_,y_))
                {
                    int absdiff=abs(heights[x_][y_]-heights[x][y]);
                    int maxdiff=max(d,absdiff);
                    if(dist[x_][y_]>maxdiff)
                    {
                        dist[x_][y_]=maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        }
        return dist[m-1][n-1];

    }
};