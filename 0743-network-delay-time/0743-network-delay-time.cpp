class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1e9;
        vector<vector<pair<int, int>>> adj(n + 1); 
        for (auto &edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Dijkstra
        vector<int> dist(n + 1, inf);
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            if (visited[node]) continue;
            visited[node] = true;

            for (auto &[neighbor, weight] : adj[node]) {
                if (!visited[neighbor] && dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == inf) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
