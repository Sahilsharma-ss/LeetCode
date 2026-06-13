class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto i : words)
            {
                int sum = 0;
                for(auto j : i)
                    {
                        
                        sum += weights[j- 'a'];
                    }
                int c = (sum%26);
                ans += ('z'-c);
            }
        return ans;
    }
};