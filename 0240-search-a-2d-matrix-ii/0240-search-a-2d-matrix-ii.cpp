class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(auto &i : matrix)
       {
        int j=0;
        int n=i.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(i[mid]==target)
            {
                return true;
            }
            else if(i[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
       }
       return false;
    }
};