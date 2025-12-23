class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<pair<int, int>> vec;
        for (auto i : events) {
            vec.push_back({i[0], i[2]});
        }
        sort(vec.begin(), vec.end(),
             [&](auto& a, auto& b) { return a.first < b.first; });
        for (int i = n - 2; i >= 0; i--) {
            vec[i].second = max(vec[i].second, vec[i + 1].second);
        }
        int maxi = -1e9;
        for (auto i : events) {
            int curr = i[2];
            auto it =
                upper_bound(vec.begin(), vec.end(), make_pair(i[1], INT_MAX));
            if (it != vec.end()) {
                curr += it->second;
            }
            maxi = max(maxi, curr);
            cout << maxi << endl;
        }
        return maxi;
    }
};