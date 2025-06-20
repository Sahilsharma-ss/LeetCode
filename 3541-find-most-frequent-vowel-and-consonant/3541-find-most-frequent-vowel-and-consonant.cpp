class Solution {
public:

    bool isvowel(char ch)
    {
        if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        int vmax=0;
        int cmax=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                mp[s[i]]++;
                vmax=max(vmax,mp[s[i]]);
            }
            else
            {
                mp[s[i]]++;
                cmax=max(cmax,mp[s[i]]);
            }
        }
        return cmax+vmax;
    }
};