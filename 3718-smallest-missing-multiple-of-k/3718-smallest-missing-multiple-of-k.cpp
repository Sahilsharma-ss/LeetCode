class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto i : nums)
        {
            st.insert(i);
        }
        int mul = k;
        while(st.find(k)!=st.end())
        {
            k+=mul;
        }
        return k;
    }
};