class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> vec(n, -1);
        unordered_set<int> full;

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (full.find(lake) != full.end()) {
                    return {};
                }
                full.insert(lake);
                vec[i] = -1;
            } 
            else { 
                bool dried = false;
                for (int j = i + 1; j < n; j++) {
                    if (rains[j] > 0 && full.find(rains[j]) != full.end()) {
                        vec[i] = rains[j];  
                        full.erase(rains[j]);
                        dried = true;
                        break;
                    }
                }
                if (!dried) {
                    vec[i] = 1; 
                }
            }
        }
        return vec;
    }
};
