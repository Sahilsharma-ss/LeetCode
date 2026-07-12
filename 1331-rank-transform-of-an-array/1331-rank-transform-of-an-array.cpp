class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int rank = 1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end()) mp[arr[i]] = rank++;
        }
        vector<int>res;
        for(int i =0;i<n;i++)
        {
            res.push_back(mp[v[i]]);
        }
        return res;
    }
};