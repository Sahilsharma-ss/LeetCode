class Solution {
public:
    int count_set_bit(int n) {
        int cnt = 0;
        while (n != 0) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        if (start == goal)
            return 0;
        int ans = start ^ goal;
        return count_set_bit(ans);
    }
};