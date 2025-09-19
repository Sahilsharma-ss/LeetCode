class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int onwards=s.size();
        for(int i=s.size()-1;i>0;i--)
        {
            if(s[i-1]>s[i])
            {
               s[i-1]--;
               onwards=i;
            }
        }
        for(int i=onwards;i<s.size();i++)
        {
            s[i]='9';
        }
        int res = stoi(s);
        return res;
    }
};