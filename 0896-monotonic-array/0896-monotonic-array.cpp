class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int m_d=false;
        int m_in=false;
        int cnt1=0,cnt2=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<=nums[i])
            {
                cnt1++;
            }
            if(nums[i-1]>=nums[i])
            {
                cnt2++;;
            }
        }
        if(cnt1==n-1) return true;
        if(cnt2==n-1) return true;
        return false;
    }
};