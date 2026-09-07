class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // direction:
        // 0 = up
        // 1 = down
        // 2 = left
        // 3 = right
        //
        // 4 = starting state (no previous direction)

        const long long INF = 1e18;

        vector<vector<vector<vector<long long>>>> dist(
            m, vector<vector<vector<long long>>>(
                   n, vector<vector<long long>>(
                          5, vector<long long>(k + 1, INF))));

        using State = tuple<long long, int, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0][4][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 4, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, r, c, prevDir, turns] = pq.top();
            pq.pop();

            if (cost != dist[r][c][prevDir][turns])
                continue;

            if (r == m - 1 && c == n - 1)
                return cost;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newTurns = turns;

                if (prevDir != 4 && prevDir != d)
                    newTurns++;

                if (newTurns > k)
                    continue;

                long long newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][d][newTurns]) {
                    dist[nr][nc][d][newTurns] = newCost;

                    pq.push({
                        newCost,
                        nr,
                        nc,
                        d,
                        newTurns
                    });
                }
            }
        }

        return -1;
    }
};