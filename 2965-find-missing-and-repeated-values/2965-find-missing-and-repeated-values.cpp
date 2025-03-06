class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> oned;
        vector<int> vec;
        vector<int> res(2, 0);
        int missing;
        int two;
        int n = grid.size();
        for (int i = 1; i < (n * n); i++) {
            vec.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                oned.push_back(grid[i][j]);
            }
        }
        map<int, int> mp;
        for (auto i : oned) {
            mp[i]++;
        }
        for (auto& i : mp) {
            if (i.second == 2) {
                two = i.first;
            }
        }
        int j = 0;
        set<int> s(oned.begin(), oned.end());
        for (int i = 1; i <= (n * n); i++) {
            if (s.find(i) == s.end()) {
                missing = i;
                break;
            }
        }

        res[0] = two;
        res[1] = missing;
        return res;
    }
};