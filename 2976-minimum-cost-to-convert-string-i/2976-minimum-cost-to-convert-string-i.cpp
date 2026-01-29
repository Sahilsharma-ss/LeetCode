class Solution {
public:
    const long long INF = 1e18;

    void diji(char c,
              unordered_map<char, vector<pair<char,int>>>& mp,
              vector<long long>& dist)
    {
        dist.assign(26, INF);
        dist[c - 'a'] = 0;

        priority_queue<pair<long long,char>,
                       vector<pair<long long,char>>,
                       greater<pair<long long,char>>> pq;

        pq.push({0, c});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u - 'a']) continue;

            for (auto &it : mp[u]) {
                char v = it.first;
                int w = it.second;

                if (dist[v - 'a'] > d + w) {
                    dist[v - 'a'] = d + w;
                    pq.push({dist[v - 'a'], v});
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost)
    {
        unordered_map<char, vector<pair<char,int>>> mp;

        int n = original.size();
        for (int i = 0; i < n; i++) {
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> allDist(26, vector<long long>(26, INF));
        vector<long long> dist;
        for (char c = 'a'; c <= 'z'; c++) {
            diji(c, mp, dist);
            allDist[c - 'a'] = dist;
        }

        long long ans = 0;
        int l = source.size();

        for (int i = 0; i < l; i++) {
            char s = source[i];
            char t = target[i];

            if (s == t) continue;

            if (allDist[s - 'a'][t - 'a'] == INF)
                return -1;

            ans += allDist[s - 'a'][t - 'a'];
        }

        return ans;
    }
};
