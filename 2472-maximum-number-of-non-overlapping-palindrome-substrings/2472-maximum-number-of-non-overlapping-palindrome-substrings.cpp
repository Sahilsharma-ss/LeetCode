class Solution {
public:
    // int solve(int ind ,int prev ,vector<vector<int>>&intervals,vector<vector<int>>&dp)
    // {
    //     if(ind>=intervals.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int take = -1e9;
    //     if(prev==-1 || intervals[ind][0]>prev)
    //     {
    //         take = 1 + solve(ind+1,intervals[ind][1],intervals,dp);
    //     }
    //     int not_take = 0+solve(ind+1,prev,intervals,dp);
    //     return dp[ind][prev+1] = max(take,not_take);
    // }
    int solve(int ind, string &s, int k,
              vector<vector<int>>& pal,
              vector<int>& dp)
    {
        if(ind >= s.size())
        {
            return 0;
        }

        if(dp[ind] != -1)
        {
            return dp[ind];
        }

        // Don't take any palindrome starting at ind
        int not_take = solve(ind + 1, s, k, pal, dp);

        int take = 0;

        // Try every palindrome starting at ind
        for(int j = ind + k - 1; j < s.size(); j++)
        {
            if(pal[ind][j])
            {
                take = max(take,
                           1 + solve(j + 1, s, k, pal, dp));
            }
        }

        return dp[ind] = max(take, not_take);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // have to build a dp table which will tell substring from i to j is pallindrome or not it will take O(n^2)
        vector<vector<int>>dp(n,vector<int>(n,false));
        // size 1
        for(int i=0;i<n;i++)
        {
            dp[i][i] = true;
        }
        // size 2
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
            }
        }
        // size 3 to n
        for(int len =3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j = i+len-1;
                dp[i][j] =((s[i]==s[j]) && dp[i+1][j-1] );
    // curr s[i]==s[j] && and their internal i+1 , j-1 th substring is already pallindrome
            }   
        }


        // vector<vector<int>>intervals;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(dp[i][j] && (j-i+1) >=k)
        //         {
        //             intervals.push_back({i,j});
        //            // cout<<i<<" "<<j<<endl;
        //         }
        //     }
        // }
        vector<int> dp1(n + 1, -1);
        return solve(0, s, k,dp, dp1);
    }
};