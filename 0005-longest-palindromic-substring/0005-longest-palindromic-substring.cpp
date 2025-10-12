class Solution {
public:
    bool valid(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (valid(s, i, j) && (j - i + 1) > maxi) {
                    ans = s.substr(i, j - i + 1);
                    maxi = j - i + 1;
                }
            }
        }

        return ans;
    }
};
