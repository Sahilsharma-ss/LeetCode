class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(auto i : deck)
        {
            mp[i]++;
        }
        set<int>st;
        int ele=deck[0];
        int g=mp[deck[0]];
        for(auto i : mp)
        {
            g=gcd(g,i.second);
        }
        if(g<=1) return false;
        for(auto i : mp)
        {
            if(i.second<=1) return false;
            if(i.second%g==0)
            {
               st.insert(g);
            }
            else
            {
                st.insert(i.second);
            }
        }
        return st.size()==1?true:false;
    }
};