class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = * max_element(nums.begin(),nums.end());
        unordered_set<int>st;
        for(auto i : nums)
            {
                st.insert(i);
            }
        vector<int>vec1;
        for(int i=mini ; i<=maxi;i++)
            {
                vec1.push_back(i);
            }
        vector<int>res;
        for(auto i : vec1)
            {
                if(!st.count(i))
                {
                    res.push_back(i);
                }
            }
        return res;
    }
};