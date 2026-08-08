class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;
       for(auto i : strs)
       {
            string str = i;
            sort(i.begin(),i.end());
            mp[i].push_back(str);
       }
       vector<vector<string>>ans;
       for(auto i : mp)
       {
            ans.push_back(i.second);
       }
        return ans;
    }
};