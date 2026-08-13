class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            if(!st.empty() && st.top()==mp[s[i]])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};