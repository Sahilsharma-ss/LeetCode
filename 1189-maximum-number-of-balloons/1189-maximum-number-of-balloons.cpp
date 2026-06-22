class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int>mp;
        for(auto i : text)
        {
            mp[i]++;
        }
        int ans   = min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
        return ans;
    }
};