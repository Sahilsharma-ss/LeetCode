class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int c = 0;
        int maxLength = 0;
        int start = 0;

        while (s[i] != '\0') {
            string str = s.substr(start, i - start);
            if (str.find(s[i]) != std::string::npos) {
                start++;
            } else {
                c = i - start + 1;
                maxLength = max(maxLength, c);
                i++;
            }
        }

        return maxLength;
    }
};
