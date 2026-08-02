class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }

        long long total = prefix.back();
        long long completedWork = 0;

        vector<int> ans;

        for (int shift : shifts) {
            completedWork += shift;

            if (completedWork >= total) {
                ans.push_back(0);
                completedWork = 0; 
            } else {
                int completed = upper_bound(prefix.begin(), prefix.end(), completedWork) - prefix.begin();
                ans.push_back(n - completed);
            }
        }

        return ans;
    }
};