class Solution {
public:
    bool check( unordered_map<int,int>&mp,int k)
    {
        int maxi = 0;
        int sum =0 ;
        for(auto i : mp)
        {
            maxi = max(maxi,i.second);
            sum += i.second;
        }
        return sum-maxi<=k;
    }
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mp;
        int l =0;
        int r =0;
        int n =s.size();
        int ans =0 ;
        while(r<n)
        {
            mp[s[r]]++;
            while(l<n && !check(mp,k))
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(s[l]);
                }
                l++;
            } 
            if(check(mp,k))
            {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};