class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int num : nums1) xor1 ^= num;
        for (int num : nums2) xor2 ^= num;
        int n1 = nums1.size(), n2 = nums2.size();
        int result = 0;

        if (n2 % 2 == 1) result ^= xor1;
        if (n1 % 2 == 1) result ^= xor2; 

        return result;
    }
};
