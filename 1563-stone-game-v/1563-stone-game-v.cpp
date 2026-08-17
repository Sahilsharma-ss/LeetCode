class Solution {
public:
    int n;
    vector<int>psum;
    vector<vector<int>>dp;
    int solve(int l,int r,vector<int>& stoneValue)
    {
        if(r==l) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int k=l;k<=(r-1);k++)
        {
            int lsum = l>0?psum[k]-psum[l-1]:psum[k]-0;
            int rsum = (l>0?psum[r]-psum[l-1]:psum[r]) - lsum;
            if(lsum<rsum)
            {
                ans = max(ans,lsum + solve(l,k,stoneValue));
            }
            else if(lsum==rsum)
            {
                ans  = max({ans,rsum + solve(k+1,r,stoneValue),lsum + solve(l,k,stoneValue)});
            }
            else
            {
                ans = max(ans,rsum+solve(k+1,r,stoneValue));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        psum.resize(n,0);
        psum[0] = stoneValue[0];
        dp.resize(n,vector<int>(n,-1));
        for(int i=1;i<n;i++)
        {
            psum[i] = psum[i-1]+ stoneValue[i];
        }
        return solve(0,n-1,stoneValue);
    }
};