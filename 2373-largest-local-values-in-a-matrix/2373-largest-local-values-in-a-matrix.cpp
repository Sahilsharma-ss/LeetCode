class Solution {

public:

    int largestLocalUtil(vector<vector<int>>& grid, int x, int y) {
        int curMax = 0;
        
        for (int i = x-1 ; i <= x+1 ; i++) {
            for (int j = y-1 ; j <= y+1 ; j++) {
                curMax = max(curMax, grid[i][j]);
            }
        }
        
        return curMax;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int i = 1 ; i < n-1 ; i++) {
            for (int j = 1 ; j < n-1 ; j++) {
                grid[i-1][j-1] = largestLocalUtil(grid, i, j);
            }
        }
        
        int m = n-2;
        
        grid.resize(m);
        
        for (int i = 0 ; i < m ; i++) grid[i].resize(m);
        
        return grid;
    }
};