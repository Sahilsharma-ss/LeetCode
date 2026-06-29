class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string i : patterns)
        {
            if(word.find(i) != std :: string::npos)
            {
                cnt++;
            }
        }
        return cnt;
    }
};