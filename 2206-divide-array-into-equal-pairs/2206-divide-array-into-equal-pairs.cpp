class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size()/2;
        for(auto i : nums)
        {
            mp[i]++;
        }
        int cnt=0;
        for(auto i : mp)
        {
            int n =i.second/2;
            cnt +=n;
        }
        if(cnt==n) return true;
        return false;
    }
};