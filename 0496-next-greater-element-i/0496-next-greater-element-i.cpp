class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && nums2[i]>nums2[st.top()])
            {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int>res;
        for(int i : nums1){
            if(mp[i]==0)
            {
                res.push_back(-1);
                continue;
            }
            res.push_back(mp[i]);
        }
        
        return res;
    }
};