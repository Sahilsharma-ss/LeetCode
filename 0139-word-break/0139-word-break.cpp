class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 0; i < n; i++) {

            if (!dp[i])
                continue;

            string word = "";

            for (int j = i; j < n; j++) {

                word += s[j];

                if (st.count(word)) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};