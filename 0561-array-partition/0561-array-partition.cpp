class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
      int m=nums.size()/2;
      vector<int>psum(n-1,0);
      for(int i=0;i<n-1;i++)
      {
        psum[i]=min(nums[i],nums[i+1]);
      }
      int sum=0;
      for(int i=0;i<m;i++)
      {
        sum=sum+psum[i];
      }
      return sum;
    }
};