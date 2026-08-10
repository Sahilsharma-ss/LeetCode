class Solution {
public:
    vector<int>dp;
    int solve(int n)
    {
        if(n==0)
        {
            return false;
        }
        if(dp[n]!=-1) return dp[n];
        for(int i =1;i*i<=n;i++)
        {
            if(solve(n-(i*i))==false)// call for bob if false return true means alice win
            {
                return dp[n] = true;// alice win
            }
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return solve(n);// call for alice with n stone
    }
};