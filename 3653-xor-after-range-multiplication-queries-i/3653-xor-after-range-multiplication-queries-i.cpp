class Solution {
public:
    const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto i : queries)
        {
            int idx=i[0],r=i[1],k=i[2],v=i[3];
            while(idx<=r)
            {
                long long no=nums[idx];
                long long ans=(no*v)%mod;
                nums[idx]=(int)ans;
                idx+=k;
            }
        }
        int res=0;
        for(auto i : nums)
        {
            res=res^i;
        }
        return res;
    }
};