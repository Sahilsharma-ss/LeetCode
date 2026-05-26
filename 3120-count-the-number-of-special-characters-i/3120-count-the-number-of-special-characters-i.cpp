class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        // unordered_set<char>st;
        // for(auto i : word)
        // {
        //     st.insert(i);
        // }
        // for(auto i : word)
        // {

        // }
        vector<int>a(26,0),A(26,0);
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(ch>='a' && ch<='z')
            {
                a[ch-'a'] = 1;
            }
            if(ch>='A' && ch<='Z')
            {
                A[ch-'A']  = 1;
            }
        }
        for(auto i=0;i<26;i++)
        {
            if(a[i] && A[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};