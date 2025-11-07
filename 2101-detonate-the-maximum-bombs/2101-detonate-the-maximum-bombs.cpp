class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        // Step 1: Build a graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long dx = x2 - x1;
                long long dy = y2 - y1;
                long long dist2 = dx * dx + dy * dy;

                // if bomb j is within the radius of bomb i, i can detonate j
                if (dist2 <= r1 * r1) {
                    graph[i].push_back(j);
                }
            }
        }

        // Step 2: DFS function to count detonations
        auto dfs = [&](int node, vector<int>& visited, auto&& dfs_ref) -> int {
            visited[node] = 1;
            int count = 1; // include current bomb
            for (int next : graph[node]) {
                if (!visited[next]) {
                    count += dfs_ref(next, visited, dfs_ref);
                }
            }
            return count;
        };

        // Step 3: Try detonating from each bomb
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            ans = max(ans, dfs(i, visited, dfs));
        }

        return ans;
    }
};
