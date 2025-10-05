class Solution {
public:
    int n, m;
    vector<pair<int,int>> dir{{-1,0},{0,1},{1,0},{0,-1}};

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<int>>& visited) {
        while(!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            for(auto d : dir) {
                int i_ = a + d.first;
                int j_ = b + d.second;

                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                   !visited[i_][j_] && heights[i_][j_] >= heights[a][b]) {
                    visited[i_][j_] = 1;
                    q.push({i_, j_});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacificVisited(n, vector<int>(m, 0));
        vector<vector<int>> atlanticVisited(n, vector<int>(m, 0));

        queue<pair<int,int>> qP, qA;
        for(int i = 0; i < n; i++) {
            qP.push({i, 0});
            pacificVisited[i][0] = 1;
        }
        for(int j = 0; j < m; j++) {
            qP.push({0, j});
            pacificVisited[0][j] = 1;
        }

        for(int i = 0; i < n; i++) {
            qA.push({i, m-1});
            atlanticVisited[i][m-1] = 1;
        }
        for(int j = 0; j < m; j++) {
            qA.push({n-1, j});
            atlanticVisited[n-1][j] = 1;
        }
        bfs(heights, qP, pacificVisited);
        bfs(heights, qA, atlanticVisited);

        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
