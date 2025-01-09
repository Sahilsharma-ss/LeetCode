class Solution {
public:
    bool detectCapitalUse(string word) {
            int c=0,i =0;
            for( i =0;i<word.size();i++)
            {
                if(isupper(word[i]))
                {
                    c++;
                }
            }
            if(c==word.size()) 
            {
                return true;
            }
            c=0;
            if(!isupper(word[i]))
            {
                for(int i=0;i<word.size();i++)
                {
                    if(!isupper(word[i]))
                    {
                        c++;
                    }
                }
            }
            if(c==word.size())
            {
                return true;
            }
            c=0;
            if(isupper(word[0]))
            {
                for(int i=1;i<word.size();i++)
                {
                    if(!isupper(word[i]))
                    {
                        c++;
                    }
                }
            }
            if(c+1==word.size())
            {
                return true;
            }

            return false;
    }
};