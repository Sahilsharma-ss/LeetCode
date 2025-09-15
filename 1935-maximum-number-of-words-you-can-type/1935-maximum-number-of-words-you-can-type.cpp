class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt=0;
        int n=text.size();
        int i=0;
        while(i<n)
        {
            bool broken=false;
            while(i<n && text[i]!=' ')
            {
                if(brokenLetters.find(text[i])!=string::npos)
                {
                    broken=true;
                    break;
                }
                i++;
            }
            if(!broken)
            {
                cnt++;
            }
            else
            {
                while(i<n&&text[i]!=' ')  i++;
            }
            i++;
        }
        return cnt;
    }
};