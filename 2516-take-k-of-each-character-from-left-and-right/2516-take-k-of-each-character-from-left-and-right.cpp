class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);

        for (char c : s) {
            total[c - 'a']++;
        }

        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }

        int l = 0;
        int r = 0;
        vector<int> window(3, 0);
        int maxi = 0;

        while (r < n) {
            window[s[r] - 'a']++;

            while (window[0] > total[0] - k || 
                   window[1] > total[1] - k || 
                   window[2] > total[2] - k) {
                window[s[l] - 'a']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return n - maxi;
    }
};
