class Solution {
public:
    bool check(vector<int>&str,vector<int>&vec)
    {
        for(int i =0;i<256;i++)
        {
            if(str[i]<vec[i])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>vec(256,0);
        for(int i : t)
        {
            vec[i]++;
        }
        vector<int>str(256,0);
        int l =0 ;
        int r =0;
        int n = s.size();
        pair<int,int> ans = {-1,-1};
        int maxi = 1e9;
        while(r<n)
        {
            str[s[r]]++;
            while(l<n && str[s[l]]>vec[s[l]])
            {
                str[s[l]]--;
                l++;
            }
            if(check(str,vec))
            {
                if(r-l+1 < maxi)
                {
                    maxi = r-l+1;
                    ans  = {l,r};
                }
            }
            r++;
        }
        if(ans.first==-1 && ans.second) return "";
        return s.substr(ans.first,ans.second-ans.first+1);
        
    }
};