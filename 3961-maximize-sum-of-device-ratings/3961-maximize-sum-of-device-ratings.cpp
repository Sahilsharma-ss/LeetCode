class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        if (units[0].size() == 1) {
            long long ans = 0;
            for (auto &row : units)
                ans += row[0];
            return ans;
        }

        vector<pair<int,int>> v;

        for (auto &row : units) {
            sort(row.begin(), row.end());
            v.push_back({row[0], row[1]});
        }

        long long sum = 0;
        int globalMin = INT_MAX;
        int smallestSecond = INT_MAX;

        for (auto &[mn1, mn2] : v) {
            sum += mn2;
            globalMin = min(globalMin, mn1);
            smallestSecond = min(smallestSecond, mn2);
        }

        return sum - smallestSecond + globalMin;
    }
};