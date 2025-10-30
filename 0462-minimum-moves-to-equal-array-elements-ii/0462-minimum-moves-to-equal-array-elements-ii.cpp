class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // ✅ Must sort first!

        vector<long long> p(n), s(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] + nums[i];

        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            s[i] = s[i + 1] + nums[i];

        long long mini = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long left = 1LL * nums[i] * i - (i > 0 ? p[i - 1] : 0);
            long long right = (i < n - 1 ? s[i + 1] : 0) - 1LL * nums[i] * (n - i - 1);
            long long cost = left + right;
            mini = min(mini, cost);
        }

        return (int)mini;
    }
};
