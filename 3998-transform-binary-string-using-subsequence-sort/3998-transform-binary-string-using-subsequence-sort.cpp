class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int one = 0, zero = 0;
        int n = s.size();

        for (char c : s) {
            if (c == '0') zero++;
            else one++;
        }

        vector<int> pref(n);
        pref[0] = (s[0] == '1');
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + (s[i] == '1');

        vector<bool> res;

        for (auto str : strs) {

            int z = 0, o = 0, q = 0;

            for (char c : str) {
                if (c == '0') z++;
                else if (c == '1') o++;
                else q++;
            }

            if (z > zero || o > one) {
                res.push_back(false);
                continue;
            }

            if ((zero - z) + (one - o) != q) {
                res.push_back(false);
                continue;
            }

            int needOne = one - o;

            // Fill ? from right to left
            for (int i = n - 1; i >= 0; i--) {
                if (str[i] == '?') {
                    if (needOne > 0) {
                        str[i] = '1';
                        needOne--;
                    } else {
                        str[i] = '0';
                    }
                }
            }

            int cur = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (str[i] == '1')
                    cur++;

                if (cur > pref[i]) {
                    ok = false;
                    break;
                }
            }

            res.push_back(ok);
        }

        return res;
    }
};