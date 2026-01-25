#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(int src, vector<vector<int>>& adj, int n) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx = bfs(x, adj, n);
        vector<int> dy = bfs(y, adj, n);
        vector<int> dz = bfs(z, adj, n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> v = {dx[i], dy[i], dz[i]};
            sort(v.begin(), v.end());
            if (v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) {
                ans++;
            }
        }
        return ans;
    }
};
