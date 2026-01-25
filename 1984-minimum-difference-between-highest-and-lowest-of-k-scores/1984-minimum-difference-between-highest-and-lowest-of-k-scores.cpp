class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums.size()==1) return 0;
        int ans = 1e9;
        for(int i=0;i<=nums.size()-k;i++)
        {
            ans = min(ans,(nums[i]-nums[i+k-1]));
        }
        return ans;
    }
};