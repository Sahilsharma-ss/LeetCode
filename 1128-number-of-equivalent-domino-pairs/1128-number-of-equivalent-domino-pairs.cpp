
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> countMap;
        int count = 0;

        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            string key = to_string(a) + "," + to_string(b);
            count += countMap[key];
            countMap[key]++;
        }

        return count;
    }
};
