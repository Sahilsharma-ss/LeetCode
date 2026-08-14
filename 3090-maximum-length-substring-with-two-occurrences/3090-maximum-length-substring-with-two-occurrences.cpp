class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>mp;
        int l =0;
        int r =0;
        int n = s.size();
        int ans =0;
        while(r<n)
        {
            mp[s[r]]++;
            while(l<n && mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};