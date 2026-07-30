class Solution {
public:
    int minimumPushes(string word) {
        int sz = word.size();
        cout<<sz;
        if(sz<=8)
        {
            return sz;
        }
        else if(sz>8 && sz<=16)
        {
            return 8+((sz-8)*2);
        }
        else if(sz>16 && sz<=24)
        {
            return 8+16+((sz-16)*3);
        }
        else
        {
            return 8+16+24 + (sz-24)*4;
        }
        return 0;
    }
};