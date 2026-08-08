class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
         int maxi = 0;
         int n = nums.size();
         unordered_set<int>st(nums.begin(),nums.end());
         for(auto i : st)
         {
            if(st.find(i-1)==st.end())
            {
                int curr = i;
                int cnt = 1;
                while(st.find(curr+1)!=st.end())
                {
                    cnt++;
                    curr++;
                }
                maxi = max(maxi,cnt);
            }
         }
         return maxi;
    }
};