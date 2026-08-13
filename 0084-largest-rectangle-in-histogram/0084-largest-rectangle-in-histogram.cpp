class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1) return heights[0];
        int n = heights.size();
        stack<int>st;
        vector<int>inc(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                inc[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        vector<int>dec(n,-1);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                dec[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i =0;i<n;i++)
        {
            maxi = max(maxi,(inc[i]-dec[i]-1)*heights[i]);
        }
        return maxi;
    }
};