class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i =0;
        int cnt = 0;
        while(i<n)
        {
            if(s[i]=='1')
            {
                if(cnt == 1) return false;
                while(i<n && s[i]=='1')
                {
                    i++;
                }
                cnt++;
            }
            i++;
        }
        return true;
    }
};