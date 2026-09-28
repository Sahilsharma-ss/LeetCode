class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(1);
            }
            else if(s[i]==')')
            {
                st.pop();
            }
            ans = max(ans,(int)st.size());
        }
        return ans;
    }
};