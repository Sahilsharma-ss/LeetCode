class Solution {
public:
    int lb(vector<int>& nums, int l, int r, int t) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    int ub(vector<int>& nums, int l, int r, int t) {
        while (l <= r) {  
            int mid = l + (r - l) / 2;
            if (nums[mid] <= t) {  
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};  
        int l = 0, r = nums.size() - 1;
        int left = lb(nums, l, r, target);
        int right = ub(nums, l, r, target);

       
        if (left <= right && nums[left] == target) {
            return {left, right};
        }
        return {-1, -1};
    }
};

