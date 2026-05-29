class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,set<string>>mp;
        for(auto i : products)
        {
            string str = "";
            for(int j=0;j<i.size();j++)
            {
                str += i[j];
                mp[str].insert(i);
            }
        }
        vector<vector<string>>res;
        string tmp = "";
        for(char ch  : searchWord)
        {
            tmp+=ch;
            vector<string>ans;
            auto it = mp[tmp].begin();
            for(int i=0;i<min((int)mp[tmp].size(),3);i++)
            {
                ans.push_back(*it);
                it++;
            }
            res.push_back(ans);
        }
        return res;
    }
};