class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        
        priority_queue<pair<double,pair<int,int>>> pq;
        int n = classes.size();
        for (auto &clas : classes) {
            pq.push({gain(clas[0], clas[1]), {clas[0], clas[1]}});
        }
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }
        double totalAvg = 0.0;
        while (!pq.empty()) {
            auto [g, pr] = pq.top(); pq.pop();
            totalAvg += (double)pr.first / pr.second;
        }
        
        return totalAvg / n;
    }
};
