class Solution {
public:
    bool isvalid(string &s , int st ,int end)
    {
        while(st<end)
        {
            if(s[st++]!=s[end--]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isvalid(s,i,j))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};