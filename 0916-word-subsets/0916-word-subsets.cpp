class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        for (const auto& word1 : words1) {
            int size = 0;
            for (const auto& word2 : words2) {
                if (word1.find(word2) == std::string::npos) {
                    size++;
                }
            }
            if (size == 0) {
                res.push_back(word1);
            }
        }
        return res;
    }
};
