class Solution {
public:
    bool solve(int i,int j,string s,string p)
    {
        if(i<0) return true;
        if(j<0) return false;
        if(i==0) return s[i]==p[j];

        if(s[i]==p[j]||p[i]=='?')
        {
            return solve(i-1,j-1,s,p);
        }
        else if(p[i]=='*')
        {
            return true;
        }
        else
        {
            return solve(i-1,j,s,p);
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='*') return true;
        }
        return solve(n-1,m-1,s,p);
    }
};