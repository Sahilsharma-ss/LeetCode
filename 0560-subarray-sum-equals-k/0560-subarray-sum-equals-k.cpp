class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int psum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            psum+=nums[i];
            int tar = psum-k;
            if(mp.count(tar))
            {
                ans+=mp[tar];
            }
            mp[psum]++;
        }
        return ans;
    }
};