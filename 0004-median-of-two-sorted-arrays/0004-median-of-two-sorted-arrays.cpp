class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec=nums1;
        vec.insert(vec.end(),nums2.begin(),nums2.end());
        sort(vec.begin(),vec.end());
        int size = vec.size();
        if(size%2==0)
        {
            return (double) (vec[(double)size/2]+vec[(double)size/2-1])/2;
        }
        else
        {
            return (double) vec[size/2];
        }
    }
};