class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i :s)
        {
            mp[i]++;
        }
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](pair<char,int>&a, pair<char,int>&b){
            return a.second>b.second;
        });
        string res="";
        for(auto &i : vec)
        {
            for(int j=0;j<i.second;j++)
            {
                res+=i.first;
            }
        }
        return res;
    }
};