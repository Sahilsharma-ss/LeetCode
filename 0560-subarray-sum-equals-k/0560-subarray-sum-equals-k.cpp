class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int presum=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            presum +=nums[i];
            int rmv = presum-k;
            cnt +=mp[rmv];
            mp[presum] +=1;
        }
        return cnt;
    }
};