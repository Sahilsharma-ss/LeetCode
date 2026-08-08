class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map [{2,0},{7,1},{11,2},{15,3}]
        unordered_map<int,int>mp; // {value,index}
        int n = nums.size();
        for(int i=0;i<n;i++) // O(n)
        {
            mp[nums[i]] = i;
        }
        for(int i =0;i<n;i++) // tc : O(N);
        {
            int tar = target-nums[i];
            if(mp.find(tar)!=mp.end())
            {
                if(i != mp[tar])
                {
                    return {i,mp[tar]};
                }
            }
        }
        return {};
    }
};