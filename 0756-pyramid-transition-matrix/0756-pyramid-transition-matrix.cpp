class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;

    bool dfs(string row) {
        if (row.size() == 1) return true;
        if (bad.count(row)) return false;

        vector<string> nextRows;
        buildNext(row, 0, "", nextRows);

        for (auto &nr : nextRows) {
            if (dfs(nr)) return true;
        }

        bad.insert(row);
        return false;
    }

    void buildNext(string &row, int idx, string curr, vector<string> &res) {
        if (idx == row.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = row.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNext(row, idx + 1, curr + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
