class Solution {
public:
    vector<int>pref;
    vector<int>dp;
    int solve(int ind,vector<int>&stones)
    {
        if(ind==stones.size()-1)
        {
            return pref[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int take = pref[ind] - solve(ind+1,stones);
        int ntake = solve(ind+1,stones);
        return dp[ind] = max(take,ntake);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        pref.resize(n,0);
        pref[0] = stones[0];
        for(int i =1;i<n;i++)
        {
            pref[i] = pref[i-1]+stones[i];
        }
        dp.resize(n,0);
        // return solve(1,stones);
        dp[n-1] = pref[n-1];
        for(int i=n-2;i>=1;i--)
        {
            int take = pref[i] - dp[i+1];
            int ntake = dp[i+1];
            dp[i] = max(take,ntake); 
        }

        return dp[1];
    }
};