class Solution {
public:
    vector<pair<int,int>> dir{{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 1;

        for (auto [vx, vy] : dir) {
            int i_ = i + vx;
            int j_ = j + vy;
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && board[i_][j_] == 'O' && vis[i_][j_] == 0) {
                dfs(i_, j_, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Check first and last row
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O' && vis[0][i] == 0) dfs(0, i, vis, board);
            if (board[m - 1][i] == 'O' && vis[m - 1][i] == 0) dfs(m - 1, i, vis, board);
        }

        // Check first and last column
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && vis[i][0] == 0) dfs(i, 0, vis, board);
            if (board[i][n - 1] == 'O' && vis[i][n - 1] == 0) dfs(i, n - 1, vis, board);
        }

        // Convert unvisited 'O's to 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
