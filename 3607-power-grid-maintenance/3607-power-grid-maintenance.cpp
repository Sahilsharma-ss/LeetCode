class Solution {
public:
    int n;
    vector<int> parent, sz, offline;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> pq;
    unordered_map<int, vector<int>> adj;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];

        while (!pq[b].empty()) {
            pq[a].push(pq[b].top());
            pq[b].pop();
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        n = c;
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        offline.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            pq[i].push(i);
        }

        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            unite(u, v);
        }

        vector<int> res;
        for (auto &q : queries) {
            int type = q[0], node = q[1];
            if (type == 1) {
                if (offline[node] == 0) {
                    res.push_back(node);
                    continue;
                }
                int p = find(node);
                while (!pq[p].empty() && offline[pq[p].top()]) pq[p].pop();
                res.push_back(pq[p].empty() ? -1 : pq[p].top());
            } else {
                offline[node] = 1;
            }
        }

        return res;
    }
};
