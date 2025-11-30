class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> unique(n);
        for (int i = 0; i < n; i++) {
            int idx =
                upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            unique[i] = n - idx;
        }

        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
            if (unique[i] >= k)
                ans += (j - i + 1);
            i = j + 1;
        }

        return ans;
    }
};
