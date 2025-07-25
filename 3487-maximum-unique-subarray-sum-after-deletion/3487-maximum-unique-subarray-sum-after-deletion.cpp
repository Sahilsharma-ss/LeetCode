class Solution {
    int maxi(vector<int>&nums)
    {
        int m=-1e9;
        for(int i =0;i<nums.size();i++)
        {
            m=max(m,nums[i]);
        }
        return m;
    }
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        if(nums.size()==1) return nums[0];
        int sum=0;
        int cnt=0;
        for(auto i : mp)
        {
            if(i.first>=0&&i.second>=0)
            {
                sum+=i.first;
            }
            if(i.first<0)
            {
                cnt+=i.second;
            }
        }
        if(cnt==nums.size()) return maxi(nums);
        return sum;
    }
};