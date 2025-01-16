class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int c = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                c++;   
                i++;      
                j--;
            } else if (sum < k) {
                i++;     
            } else {
                j--;
            }
        }
        return c;
    }
};
