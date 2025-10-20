class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        multiset<int>st;
        int l=0;
        int r=0;
        long long maxi=0;
        while(r<n)
        {
            st.insert(nums[r]);
            while(abs(*st.begin()-*st.rbegin())>2)
            {
                st.erase(st.find(nums[l]));
                l++;
            }
            maxi +=r-l+1;
            r++;
        }
        return maxi;
    }
};