class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r = 0;
        int n = s.size();
        unordered_map<int,int>mp;
        int maxi = 0;
        while(r<n)
        {
            mp[s[r]]++;
            if(mp.size()<(r-l+1))
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            if(mp.size()==(r-l+1))
            {
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};