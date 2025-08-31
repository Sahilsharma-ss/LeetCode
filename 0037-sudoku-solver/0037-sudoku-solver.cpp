class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board)) return true; // solved
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no digit works
                }
            }
        }
        return true; // solved completely
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            // check row
            if(board[row][i] == c) return false;
            // check column
            if(board[i][col] == c) return false;
            // check 3x3 sub-box
            int boxRow = 3 * (row/3) + i/3;
            int boxCol = 3 * (col/3) + i%3;
            if(board[boxRow][boxCol] == c) return false;
        }
        return true;
    }
};
