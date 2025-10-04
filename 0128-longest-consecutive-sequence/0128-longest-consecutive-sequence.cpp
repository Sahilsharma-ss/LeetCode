class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : s) {
            if (!s.count(num - 1)) {
                int curr = num;
                int streak = 1;
                while (s.count(curr + 1)) {
                    curr++;
                    streak++;
                }
                maxi = max(maxi, streak);
            }
        }
        return maxi;
    }
};
