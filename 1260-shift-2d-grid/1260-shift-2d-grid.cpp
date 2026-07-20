class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sz = m*n;
        k = k%sz;
        vector<int>vec;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                vec.push_back(grid[i][j]);
            }
        }
        vector<int>res;
        for(int i = sz-k;i<vec.size();i++)
        {
            res.push_back(vec[i]);
        }
        for(int i =0;i<sz-k;i++)
        {
            res.push_back(vec[i]);
        }
        int ind = 0;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                grid[i][j] = res[ind++];
            }
        }
        return grid;
    }
};