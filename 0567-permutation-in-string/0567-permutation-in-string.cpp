class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>vec(26,0); // vec
        for(int i : s1)
        {
            vec[i-'a']++;  // ab     a = 1 , b = 1
        }
        vector<int>v(26,0);
        int l =0;
        int r =0;
        int n = s2.size();
        while(r<n)
        {
            v[s2[r]-'a']++;
            while(l<n && v[s2[l]-'a'] > vec[s2[l]-'a'])
            {
                v[s2[l]-'a']--;
                 l++;
            }
            if(vec==v)
            {
                return true;
            }
            r++;
        }
        return false;
    }
};