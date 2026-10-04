class Solution {
public:

    int n;
    int dp[101][101][101];

    bool solve(int ind, int open, int close, string &s)
    {
        if (close > open)
            return false;

        if (ind == n)
        {
            return open == close;
        }

        if (dp[ind][open][close] != -1)
            return dp[ind][open][close];

        if (s[ind] == '(')
        {
            if (solve(ind + 1, open + 1, close, s))
            {
                return dp[ind][open][close] = true;
            }
        }

        else if (s[ind] == ')')
        {
            if (solve(ind + 1, open, close + 1, s))
            {
                return dp[ind][open][close] = true;
            }
        }

        else if (s[ind] == '*')
        {
            if (solve(ind + 1, open + 1, close, s) ||
                solve(ind + 1, open, close + 1, s) ||
                solve(ind + 1, open, close, s))
            {
                return dp[ind][open][close] = true;
            }
        }

        return dp[ind][open][close] = false;
    }

    bool checkValidString(string s)
    {
        n = s.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, s);
    }
};