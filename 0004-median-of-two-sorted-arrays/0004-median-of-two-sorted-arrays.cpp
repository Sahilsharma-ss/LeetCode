class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        int l =0;
        int r =n;
        while(l<=r)
        {
            int px = l+(r-l)/2;
            int py = (m+n+1)/2 - px;
            //left
            int x1 = (px==0)?-1e9:nums1[px-1];
            int x2 = (py==0)?-1e9:nums2[py-1];
            //right
            int x3 = (px==n)?1e9:nums1[px];
            int x4 = (py==m)?1e9:nums2[py];

            if(x1<=x4 && x2<=x3)
            {
                if((m+n)%2==0)
                {
                    return (max(x1,x2) + min(x3,x4))/2.0;
                }
                else
                {
                    return max(x1,x2);
                }
            }

            if(x1>x4)
            {
                r = px-1;
            }
            else
            {
                l = px+1;
            }
        }
        return -1;
    }
};