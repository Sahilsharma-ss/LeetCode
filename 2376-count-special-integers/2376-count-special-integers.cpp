class Solution {
public:
    int dp[10][2][2][1<<10]; // pos,tight,leadingzero,masks(for check)

    int solve(int pos,int tight,int leadingzero,int mask,string &digits)
    {
        if(pos==digits.size())
        {
            return !leadingzero; 
        }
        if(dp[pos][tight][leadingzero][mask]!=-1) return dp[pos][tight][leadingzero][mask];
        int maxdigit = tight?digits[pos]-'0':9;
        int ans  = 0;
        for(int d=0;d<=maxdigit;d++)
        {
            if(!leadingzero && (mask & (1<<d)))
            {
                continue;
            }
            int nleadingzero = leadingzero & (d==0);
            int newmask;
            if(nleadingzero)
            {
                newmask= mask;
            }
            else
            {
                newmask= mask | (1<<d);
            }
            int newtight = tight & (d==maxdigit);
            ans += solve(pos+1,newtight,nleadingzero,newmask,digits);
        }
        dp[pos][tight][leadingzero][mask] = ans;
        return ans;
    }
    int count(string &str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,0,str);
    }
    int countSpecialNumbers(int n) {
        string str = to_string(n);
        return count(str);
    };
};