class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> temp;
            for (int i = 0; i < nums.size() / 2; i++) {
                if (i % 2 == 0) {
                    temp.push_back(min(nums[2 * i], nums[2 * i + 1]));
                } else {
                    temp.push_back(max(nums[2 * i], nums[2 * i + 1]));
                }
            }
            nums = temp; 
        }
        return nums[0];
    }
};
