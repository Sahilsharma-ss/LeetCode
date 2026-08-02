class Solution {
public:
    int ans = 0;
    vector<int> vis;

    void solve(int pos, int n) {
        if (pos > n) {
            ans++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!vis[num] && (num % pos == 0 || pos % num == 0)) {
                vis[num] = 1;
                solve(pos + 1, n);
                vis[num] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vis.assign(n + 1, 0);
        solve(1, n);
        return ans;
    }
};