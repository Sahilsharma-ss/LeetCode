class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxi = -1e9;
        multiset<int>st;
        while(r<n)
        {
            st.insert(nums[r]);
            while (abs(*st.begin() - *st.rbegin()) >limit)
            {
                st.erase(st.find(nums[l]));
                l++;
            }
            if(abs(*st.begin() - *st.rbegin())<=limit)
            {
                int sz = st.size();
                maxi = max(maxi,sz);
            }
            r++;
        }
        return maxi;
    }
};