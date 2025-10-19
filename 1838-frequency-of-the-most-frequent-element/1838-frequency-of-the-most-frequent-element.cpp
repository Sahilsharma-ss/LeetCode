class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        multiset<int>st;
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int maxi=-1e9;
        while(r<n)
        {
            sum+=nums[r];
            st.insert(nums[r]);
            while((long long)(*st.rbegin() * st.size()) - sum >k)
            {
                sum-=nums[l];
                st.erase(st.find(nums[l]));
                l++;
            }
            
            maxi = max(maxi,(int)st.size());
            r++;
        }
        return maxi;
    }
};