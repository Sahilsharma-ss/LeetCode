class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, vector<pair<int,int>>& chor)
    {
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

        // Distance to nearest thief
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        for(auto i : chor)
        {
            dis[i.first][i.second] = 0;
            q.push(i);
        }

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for(auto d : dir)
            {
                int i_ = i + d[0];
                int j_ = j + d[1];

                if(i_ < 0 || j_ < 0 || i_ >= n || j_ >= n)
                    continue;

                if(dis[i_][j_] > dis[i][j] + 1)
                {
                    dis[i_][j_] = dis[i][j] + 1;
                    q.push({i_,j_});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({dis[0][0], {0,0}});

        while(!pq.empty())
        {
            int safe = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(vis[i][j])
                continue;

            vis[i][j] = 1;

            if(i == n-1 && j == n-1)
                return safe;

            for(auto d : dir)
            {
                int i_ = i + d[0];
                int j_ = j + d[1];

                if(i_ < 0 || j_ < 0 || i_ >= n || j_ >= n || vis[i_][j_])
                    continue;

                int pass = min(safe, dis[i_][j_]);

                pq.push({pass, {i_,j_}});
            }
        }

        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<pair<int,int>> chor;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    chor.push_back({i,j});
                }
            }
        }

        return solve(grid, n, chor);
    }
};