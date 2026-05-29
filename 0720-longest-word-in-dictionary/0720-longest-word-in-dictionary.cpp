class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string>st;
        int maxi = 0;
        string ans;
        for(auto w : words)
        {
            st.insert(w);
        }
        sort(words.begin(),words.end());
        for(auto j : words)
        {
            string tmp = "";
            bool ok = true;
            for(int i=0;i<j.size();i++)
            {
                tmp+=j[i];
                if(st.find(tmp)==st.end())
                {
                    ok = false;
                    break;
                }
            }
            if(ok && j.size()>maxi)
            {
               ans = j;
               maxi = j.size();
            }
        }
        return ans;
    }
};