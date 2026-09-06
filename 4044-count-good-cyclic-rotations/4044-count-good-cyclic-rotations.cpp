class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long tot = 0;
        for(auto i : nums)
        {
            tot += i;
        }
        long long s = 0;
        int sz = nums.size()/2;
        int i=0;
        for(i=0;i<sz;i++)
        {
            s += nums[i];
        }
        int cnt =0;
        if(s != (tot-s)) cnt++;
        int l=0;
       // cout<<cnt<<endl;
        for(int st=i;st<nums.size()-1;st++)
        {
            s-=nums[l++];
            s+=nums[st];
            long long val = tot - s;
            if(val != s)
            {
                cnt++;
            }
        }
        if(cnt>=2) return cnt;
        return cnt;
    }
};