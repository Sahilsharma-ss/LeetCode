class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<vector<int>>> &dp,vector<vector<int>>&grid)
    {
        vector<int>dj={-1,0,1};
        int m=grid.size();
        int n=grid[0].size();
        if(j1<0 || j1>=n ||j2<0 ||j2>=n) return -1e8;
        int maxi=INT_MIN;
        if(i==m-1) // reach at the end row
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        for(auto k : dj)
        {
            for(auto j : dj)
            {
                if(j1==j2)
                {
                    maxi=max(maxi,grid[i][j1]+solve(i+1,j1+k,j2+j,dp,grid)); // comman reach 
                } 
                else
                {
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+k,j2+j,dp,grid));
                }
            }
        }
        return dp[i][j1][j2]= maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0,0,n-1,dp,grid);
    }
};