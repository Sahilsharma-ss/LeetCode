class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size() - 1;
        int i = 0;
        while (i < n) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                 s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')) {
                if ((s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u' ||
                     s[n] == 'A' || s[n] == 'E' || s[n] == 'I' || s[n] == 'O' || s[n] == 'U')) {
                    swap(s[i], s[n]);
                    n--;
                    i++;
                } else {
                    n--; 
                }
            } else {
                i++; 
            }
        }
        return s;
    }
};
