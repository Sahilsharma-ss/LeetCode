class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0,r=0,res=0;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp.size()==3)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) 
                {
                    mp.erase(s[l]);
                }
                res+=n-r;
                l++;
            }
            r++;
        }
        return res;
    }
};