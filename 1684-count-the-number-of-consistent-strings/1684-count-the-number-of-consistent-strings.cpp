class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        unordered_set<char> s(allowed.begin(), allowed.end());
        for (auto &i : words) {
            bool kthe = true;
            for (char k : i) {
                if (s.find(k) == s.end()) {
                    kthe = false;
                    break;
                }
            }
            if(kthe)
                res++;
        }
        return res;
    }
};