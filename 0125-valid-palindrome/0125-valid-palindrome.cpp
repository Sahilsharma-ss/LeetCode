class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int j = n - 1;
        int i = 0;
        while (j > i) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};