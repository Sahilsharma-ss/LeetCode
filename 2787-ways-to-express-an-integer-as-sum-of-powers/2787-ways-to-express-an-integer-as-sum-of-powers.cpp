class Solution {
public:
    const int mod=1e9+7;
    int solve(int ind,int power,int target,int sum,vector<vector<int>>&dp)
    {
        if(sum==target) return 1;
        if(sum>target||pow(ind,power)>target) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ways=0;
        sum+=pow(ind,power);
        ways+=solve(ind+1,power,target,sum,dp);
        sum-=pow(ind,power);
        ways+=solve(ind+1,power,target,sum,dp);
        return dp[ind][sum]=ways%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  solve(1,x,n,0,dp);
    }
};