class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int position = 0;

        while (n > 0) {
            if (n & 1) {
                power.push_back(1 << position);
            }
            n >>= 1;
            position++;
        }

        vector<int> res;
        for (auto& query : queries) {
            int st = query[0], end = query[1];
            unsigned long long prod = 1;
            for (int i = st; i <= end; i++) {
                prod = (prod * power[i]) % mod;
            }
            res.push_back(static_cast<int>(prod));
        }

        return res;
    }
};