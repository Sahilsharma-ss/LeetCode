class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int j=0;
        for(auto w : words)
        {
            for(int i=0;i<w.size();i++)
            {
                if(w[i]==x)
                {
                    ans.push_back(j);
                    break;
                }
            }
            j++;
        }
        return ans;
    }
};