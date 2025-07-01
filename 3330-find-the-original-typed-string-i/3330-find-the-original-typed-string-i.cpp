class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=0;
        for(int i=1;i<word.size();i++)
        {
           if(i<word.size()&&word[i]==word[i-1])
            {
                cnt++;
            }
        }
        return cnt+1;
    }
};