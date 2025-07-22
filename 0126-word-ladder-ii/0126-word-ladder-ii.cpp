class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (dict.find(endWord) == dict.end()) return result;

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> level;
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.length();

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (int i = 0; i < wordLen; i++) {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.find(temp) != dict.end()) {
                        if (!level.count(temp)) {
                            level[temp] = level[curr] + 1;
                            q.push(temp);
                        }
                        if (level[temp] == level[curr] + 1)
                            graph[temp].push_back(curr); 
                    }
                }
            }
        }

        if (level.find(endWord) == level.end()) return result;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, graph, path, result);
        return result;
    }

    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& graph,
             vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        for (string prev : graph[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, graph, path, result);
            path.pop_back();
        }
    }
};
