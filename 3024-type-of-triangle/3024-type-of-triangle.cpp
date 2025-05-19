class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int n = s.size();
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b > c && b + c > a && a + c > b) {
            if (n == 3)
                return "scalene";
            if (n == 2)
                return "isosceles";
            if (n == 1)
                return "equilateral";
        }
        return "none";
    }
};