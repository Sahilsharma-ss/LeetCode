class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,int>mp;
        for(auto i :word)
        {
            mp[i]++;
        }
        int ans = 0;
        vector<pair<int,int>>vec;
        for(auto i : mp)
        {
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),[&](auto &a , auto &b)
        {
           return a.second > b.second;
        });
        for(int i=0;i<vec.size();i++)
        {
            int ele = i+1;
            if(ele<=8)
            {
                ans+=vec[i].second;
            }
            else if(ele>8 && ele<=16)
            {
                ans += 2*vec[i].second;
            }
            else if(ele>16 && ele<=24)
            {
                ans += 3*vec[i].second;
            }
            else
            {
                ans += 4*vec[i].second;
            }
        }
        return ans;
    }
};