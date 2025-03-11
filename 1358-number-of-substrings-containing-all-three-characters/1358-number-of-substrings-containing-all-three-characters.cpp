class Solution {
public:
    bool ischar(char ch) { return ch == 'a' || ch == 'b' || ch == 'c'; }

    int numberOfSubstrings(std::string s) {
        int n = s.length();
        std::unordered_map<char, int> mp;
        int i = 0, j = 0, count = 0;

        while (j < n) {
            mp[s[j]]++;
            j++;

            while (mp.size() == 3) {
                count += (n - j + 1);
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        return count;
    }
};
