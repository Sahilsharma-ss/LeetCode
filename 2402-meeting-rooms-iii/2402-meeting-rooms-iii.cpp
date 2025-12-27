class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) pq.push(i);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busy;

        vector<int> res(n, 0);
        for (auto &m : meetings) {
            long long start = m[0];
            long long end   = m[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                pq.push(busy.top().second); // add room that is free now 
                busy.pop();
            }

            if (!pq.empty()) { // assign room to meeting 
                int room = pq.top();
                pq.pop();
                res[room]++;
                busy.push({end, room});
            } else {
                auto [prevEnd, room] = busy.top();
                busy.pop();
                res[room]++;
                busy.push({prevEnd + duration, room});
            }
        }

        // Step 5: find most used room
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (res[i] > res[ans]) ans = i;
        }
        return ans;
    }
};
