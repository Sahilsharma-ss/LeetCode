class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        unordered_map<char,int>charcount;
        {
            for(char ch : s)
            {
                charcount[ch]++;
            }
        }
        int oddcount=0;
        for(auto &entry : charcount)
        {
            if(entry.second%2!= 0) 
            {
                oddcount++;
            }
        }
        return oddcount<=k;
    }
};