class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int r1,int c1,int r2,vector<vector<int>>& grid)
    {
        int c2 = r1 + c1 - r2;  // both are taking one step at a time so (r1 + c1 = r2 + c2)

        if(r1>=n || c1>=n || r2>=n || c2>=n)
            return -1e9;

        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -1e9;

        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];

        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];

        int cherries = 0;

        if(r1==r2 && c1==c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        int best = max({
            solve(r1+1,c1,r2+1,grid), // down down
            solve(r1+1,c1,r2,grid),   // down right
            solve(r1,c1+1,r2+1,grid), // right down
            solve(r1,c1+1,r2,grid)    // right right
        });

        cherries += best;

        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();

        dp.assign(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n,-1)
            )
        );

        int ans = solve(0,0,0,grid);

        return max(0,ans);
    }
};