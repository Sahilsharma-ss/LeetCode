class Solution {
public:
    int findLucky(vector<int>& arr) {
        int l_no=-1;
        unordered_map<int,int>mp;
        for(auto i : arr)
        {
            mp[i]++;
        }
        for(auto &i : mp)
        {
            if(i.second==i.first)
            {
                l_no=max(l_no,i.first);
            }
        }
        return l_no;
    }
};