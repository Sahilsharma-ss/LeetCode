class Solution {
public:

    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    bool similar(string &a, string &b) {

        int diff = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] != b[i])
                diff++;

            if (diff > 2)
                return false;
        }

        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (similar(strs[i], strs[j])) {
                    unite(i, j);
                }
            }
        }

        int groups = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                groups++;
        }

        return groups;
    }
};