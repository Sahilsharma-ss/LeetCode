class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        long long prod=1;
        int maxi=0;
        if(k<=1) return 0;
        while(r<n)
        {
            prod*=nums[r];
            while( l<n && prod>=k)
            {
                prod/=nums[l];
                l++;
            }
            int sa =(r-l+1);
            maxi += sa;
            r++;
        }
        return maxi;
    }
};