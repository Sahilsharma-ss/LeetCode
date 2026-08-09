class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>ans;
      int n = nums.size();
      sort(nums.begin(),nums.end());
      for(int k =n-1;k>=0;k--)
      {
        if(k<n-1 && nums[k+1]==nums[k]) continue;
            int i= 0;
            int j =k-1;
            while(i<j)
            {
                if(nums[k]+nums[j]+nums[i]==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(i<j && nums[i]==nums[i+1]) i++;
                    while(i<j && nums[j]==nums[j-1]) j--;
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
    //    vector<vector<int>>ans(st.begin(),st.end());
       return ans;
    }
};