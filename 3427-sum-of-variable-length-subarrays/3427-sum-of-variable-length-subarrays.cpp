class Solution {
public:
    int subarraySum(vector<int>& nums) {
          int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++){
            int max_index=0;
            max_index=max(0,i-nums[i]);
            for(int j=max_index;j<=i;j++){
                sum+=nums[j];
                
            }
        }
        return sum;
    }
};
