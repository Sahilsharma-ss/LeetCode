class Solution {
public:
    int dyna(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix,int prev,int n,int m){
        if(i<0||j<0||i>=n||j>=m||matrix[i][j]<=prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=1+max({dyna(i+1,j,dp,matrix,matrix[i][j],n,m),dyna(i-1,j,dp,matrix,matrix[i][j],n,m),dyna(i,j+1,dp,matrix,matrix[i][j],n,m),dyna(i,j-1,dp,matrix,matrix[i][j],n,m)});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxval=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxval=max(maxval,dyna(i,j,dp,matrix,-1,n,m));
            }
        }
        return maxval;
    }
};