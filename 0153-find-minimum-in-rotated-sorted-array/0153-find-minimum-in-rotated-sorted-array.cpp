class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;                  
        int e = nums.size() - 1;     

        while (s < e) {
            int mid = s + (e - s) / 2;


            if (nums[mid] > nums[e]) {
                s = mid + 1;         
            } else {
                e = mid;             
            }
        }

        // At the end, s == e, which points to the smallest element
        return nums[s];
    }
};
