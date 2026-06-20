class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add virtual restrictions for building 1 (height 0) and building n (no cap)
        //    so the loop naturally covers the start and end segments too.
        restrictions.push_back({1, 0});
        bool hasN = false;
        for (auto &r : restrictions) if (r[0] == n) hasN = true;
        if (!hasN) restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end(),[&](auto &a,auto &b)
        {
            return a[0] < b[0];
        });

        int m = restrictions.size();

        // Forward pass: tighten each restriction using the previous one.
        //    A restriction can't be looser than (prev height + distance).
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + dist);
        }

        //Backward pass: tighten each restriction using the next one.
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + dist);
        }

        //Now every adjacent pair is "honest" — compute the peak between them.
        //    Peak height = (h1 + h2 + dist) / 2  (like two tents merging)
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            ans = max(ans, (h1 + h2 + dist) / 2);
        }
        return ans;
    }
};