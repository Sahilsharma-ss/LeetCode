class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      set<vector<int>>st;
      int n = nums.size();
      sort(nums.begin(),nums.end());
      for(int k =n-1;k>=0;k--)
      {
            int i= 0;
            int j =k-1;
            while(i<j)
            {
                if(nums[k]+nums[j]+nums[i]==0)
                {
                    st.insert({nums[i],nums[j],nums[k]});
                    i++;
                    j--;
                }
                else if(nums[k]+nums[j]+nums[i]<0)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
      }
       vector<vector<int>>ans(st.begin(),st.end());
       return ans;
    }
};