class Solution {
public:
    string smallestSubsequence(string s) {
            vector<int>freq(26,0);
        vector<int>used(26,0);
        stack<int>stk;
        for(auto i : s)
        {
            freq[i-'a']++;
        }

        for(auto c : s)
        {
            int idx = c-'a';
            freq[idx]--;
            if(used[idx]) continue;
            while(!stk.empty() && stk.top()>c && freq[stk.top()-'a']>0) // if we get smaller and element in stk  & have another occurence take it greedly
            {
                used[stk.top()-'a'] = 0; // unuse the element 
                stk.pop();
            }
            stk.push(c);
            used[c-'a'] = 1;
        }
        string ans = "";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};