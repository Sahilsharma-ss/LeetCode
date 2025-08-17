class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
    
    bool issafe(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        return i < m && i >= 0 && j < n && j >= 0;
    }

    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if (board[i][j] != word[idx]) return false;
        if (idx == word.size() - 1) return true;  // whole word matched

        char temp = board[i][j];  // store current char
        board[i][j] = '#';        // mark visited

        for (auto d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;
            if (issafe(ni, nj, board) && board[ni][nj] != '#') {
                if (dfs(ni, nj, board, word, idx + 1)) {
                   // board[i][j] = temp; // restore before returning
                    return true;
                }
            }
        }

        board[i][j] = temp;  // restore
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};
