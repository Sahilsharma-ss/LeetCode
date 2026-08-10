class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>vec(26,0);
        for(int i : p)
        {
            vec[i-'a']++;
        }
        vector<int>v(26,0);
        int l =0;
        int r =0;
        int n= s.size();
        vector<int>ans;
        while(r<n)
        {
            v[s[r]-'a']++;
            while(l<n && v[s[l]-'a']>vec[s[l]-'a'])
            {
                v[s[l]-'a']--;
                l++;
            }
            if(v==vec)
            {
                ans.push_back(l);
            }
            r++;
        }
        return ans;
    }
};