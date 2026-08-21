class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--)  // using 2*n-1   to give chance to each ele to find next greater 
        {
            int idx = i % n;  // access circular

            while(!st.empty() && nums[st.top()] <= nums[idx])
            {
                st.pop();
            }

            if(i < n && !st.empty())
            {
                ans[idx] = nums[st.top()];
            }

            st.push(idx);
        }

        return ans;
    }
};