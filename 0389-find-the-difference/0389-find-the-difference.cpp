class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch;
        for( int i =0; i<t.size();i++)
        {
            if(s.find(i)== std :: string :: npos)
            {
                ch =t[i];
            }
        }
        return ch ;
    }
};