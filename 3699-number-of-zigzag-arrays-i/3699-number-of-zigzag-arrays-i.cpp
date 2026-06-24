constexpr int MOD = 1'000'000'007;
typedef long long ll;
class Solution {
public:
    int m;
    int sz;
    int dp[2001][2001][2];
    int solve(int ind,int prev,int inc)
    {
        if(ind==sz) return 1;
        if(dp[ind][prev][inc]!=-1) return dp[ind][prev][inc];
        int res = 0;
        if(inc==1)
        {
            for(int val = prev+1;val<=m;val++)
            {
                res  = (res + solve(ind+1,val,0))%MOD;
            }
        }
        else
        {
            for(int val = 1;val<prev;val++)
            {
                res = (res + solve(ind+1,val,1))%MOD;
            }
        }
       return dp[ind][prev][inc] = res%MOD;
    }
    int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        sz = n;
        long long res =0;
        int dp[2001][2001][2];
    //     for(int val = 1;val<=m;val++)
    //         {
    //             res = (res + solve(1,val,1))%MOD;
    //         }
    //    for(int val = 1;val<=m;val++)
    //         {
    //             res = (res + solve(1,val,0))%MOD;
    //         }
    //         res = res%MOD;
        // return (int)res;
        for(int i =1 ;i<=m;i++)
        {
            dp[n][i][0] = 1;
            dp[n][i][1] = 1;
        }

            for(int i =n-1;i>=0;i--)
            {
                vector<ll>cs1(m+1,0);
                vector<ll>cs2(m+1,0);
                for(int nxt=1;nxt<=m;nxt++)
                {
                    cs1[nxt] = (cs1[nxt-1] + dp[i+1][nxt][0])%MOD;
                    cs2[nxt] = (cs2[nxt-1] + dp[i+1][nxt][1])%MOD;
                }
                 for(int prev = 1;prev<=m;prev++)
                    {
                        //inc
                        // for(int next = prev+1;next<=m;next++)
                        // {
                            dp[i][prev][1] = (cs1[m]-cs1[prev]+MOD)%MOD;
                        // /}
                        //dec
                        // for(int next = 1;next<prev;next++)
                        // {
                            dp[i][prev][0] = cs2[prev-1];
                        //}
                    }
            }
            for(int i =1;i<=m;i++)
            {
                res = (res+dp[1][i][1])%MOD;
                res = (res+dp[1][i][0])%MOD;
            }
            return res;
    }
};