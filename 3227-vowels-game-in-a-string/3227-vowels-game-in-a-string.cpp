class Solution {
public:
    bool doesAliceWin(string s) {
        string vow="aeiou";
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(vow.find(s[i])!=std :: string :: npos)
            {
                cnt++;
            }
        }
        if(cnt==0) return false;
        if(cnt%2==1) return true; 
        if(cnt%2==0) return true;
        return false;
    }
};