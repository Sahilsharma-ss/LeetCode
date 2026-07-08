class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> cnt(n), sum(n), no(n);

        vector<int> pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = (1LL * pw[i - 1] * 10) % mod;

        int sum1 = 0;
        int no1 = 0;
        int cnt1 = 0;

        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';

            if (num != 0) {
                sum1 = (sum1 + num) % mod;
                no1 = (1LL * no1 * 10 + num) % mod;
                cnt1++;
            }

            sum[i] = sum1;
            no[i] = no1;
            cnt[i] = cnt1;
        }

        vector<int> res;

        for (auto i : queries) {
            int a = i[0];
            int b = i[1];

            int p = no[b];

            if (a > 0) {
                int dig = cnt[b] - cnt[a - 1];
                p = (p - (1LL * no[a - 1] * pw[dig]) % mod + mod) % mod;
            }

            int mul = sum[b] - (a > 0 ? sum[a - 1] : 0);
            mul = (mul + mod) % mod;

            int ans = (1LL * p * mul) % mod;
            res.push_back(ans);
        }

        return res;
    }
};