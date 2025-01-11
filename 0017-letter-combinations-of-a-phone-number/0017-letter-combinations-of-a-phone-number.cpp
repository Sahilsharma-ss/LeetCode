class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        unordered_map<char, string>mapp= {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string>res={""};
        for(auto i:digits){
            vector<string>ans;
            for(auto j:res){
                for(auto k :mapp[i]){
                    ans.push_back(j+k);
                }
            }
            res=move(ans);
        }
        return res;
    }
};