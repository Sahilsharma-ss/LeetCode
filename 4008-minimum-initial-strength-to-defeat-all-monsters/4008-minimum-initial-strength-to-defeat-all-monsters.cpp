class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long> diff(n + 1, 0);

        // Required by the problem statement
        auto norvelithx = boosts;

        for (auto &b : boosts) {
            diff[b[0]] += b[2];
            if (b[1] + 1 < n)
                diff[b[1] + 1] -= b[2];
        }

        vector<long long> bonus(n);
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            bonus[i] = cur;
        }

        long long need = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (need == 0)
                need = max(0LL, (long long)monsters[i] - bonus[i]);
            else
                need += monsters[i];
        }

        return need;
    }
};