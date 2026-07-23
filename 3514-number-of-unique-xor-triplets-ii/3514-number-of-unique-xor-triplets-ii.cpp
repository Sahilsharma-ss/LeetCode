class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        if(n==1) return 1;
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                st.insert(nums[i]^nums[j]);
            }
        }
        vector<int>vec(st.begin(),st.end());
        unordered_set<int>ans;
        for(int i =0;i<vec.size();i++)
        {
            for(int j =0;j<n;j++)
            {
                ans.insert(vec[i]^nums[j]);
            }
        }
        return ans.size();
    }
};