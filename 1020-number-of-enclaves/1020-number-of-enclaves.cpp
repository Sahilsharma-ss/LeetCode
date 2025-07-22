class Solution {
public:
    vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                q.push({0, i});
                vis[0][i] = 1;
            }
            if (grid[m - 1][i] == 1) {
                q.push({m - 1, i});
                vis[m - 1][i] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                vis[i][n - 1] = 1;
            }
        }

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (auto [i, j] : dir) {
                int i_ = u + i;
                int j_ = v + j;
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    vis[i_][j_] == 0 && grid[i_][j_] == 1) {
                    q.push({i_, j_});
                    vis[i_][j_] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};