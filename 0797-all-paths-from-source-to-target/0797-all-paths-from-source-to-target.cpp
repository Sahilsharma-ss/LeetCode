class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        queue<vector<int>> q;
        q.push({0});

        int target = graph.size() - 1;

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            int last = path.back();

            if (last == target) {
                result.push_back(path);
            } else {
                for (int next : graph[last]) {
                    vector<int> newPath = path;
                    newPath.push_back(next);
                    q.push(newPath);
                }
            }
        }

        return result;
    }
};
