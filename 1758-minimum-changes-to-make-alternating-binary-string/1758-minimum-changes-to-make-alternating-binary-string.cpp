class Solution {
public:
    int minOperations(string s) {
            int i=1;
            char  c= '0';
            int cnt =0;
            if(s[0]!=c)
            {
                cnt++;
            }
            while(i<s.size())
            {
                if(c=='0')
                {
                    c='1';
                }
                else
                {
                    c='0';
                }
                if(s[i]!=c)
                {
                    cnt++;
                }
                i++;
            }
            c= '1';
            i=1;
            int cnt1 =0;
            if(s[0]!=c)
            {
                cnt1++;
            }
            while(i<s.size())
            {
                if(c=='0')
                {
                    c='1';
                }
                else
                {
                    c='0';
                }
                if(s[i]!=c)
                {
                    cnt1++;
                }
                i++;
            }

            return min(cnt1,cnt);
    }
};