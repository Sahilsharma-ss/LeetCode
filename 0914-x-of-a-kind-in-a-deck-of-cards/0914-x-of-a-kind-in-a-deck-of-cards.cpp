class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(auto i : deck)
        {
            mp[i]++;
        }
        set<int>st;
        int size=mp[deck[0]];
        for(auto i : mp)
        {
            if(i.second<=1) return false;
            if(i.second%size==0)
            {
               st.insert(size);
            }
            else
            {
                st.insert(i.second);
            }
        }
        return st.size()==1?true:false;
    }
};