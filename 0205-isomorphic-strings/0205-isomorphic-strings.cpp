class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=t.size();
        unordered_map<int,unordered_set<char>>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]].insert(t[i]);
        }
        unordered_set<int>st;
        for(auto i : mp)
        {
            if(i.second.size() >1)
            {
                return false;
            }
            else
            {
                auto it = i.second.begin();
                st.insert(*it);
            }
        }
        if(st.size()!=mp.size()) return false;
        return true;
    }
};