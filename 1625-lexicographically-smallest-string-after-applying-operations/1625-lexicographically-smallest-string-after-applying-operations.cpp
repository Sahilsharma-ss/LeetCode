class Solution {
public:
    string addOp(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }

    string rotateOp(string s, int b) {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> seen;
        string ans = s;

        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);
            string added = addOp(cur, a);
            if (!seen.count(added)) {
                seen.insert(added);
                q.push(added);
            }
            string rotated = rotateOp(cur, b);
            if (!seen.count(rotated)) {
                seen.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};
