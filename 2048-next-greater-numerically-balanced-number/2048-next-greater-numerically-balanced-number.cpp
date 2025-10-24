class Solution {
public:
    bool check(array<int,10>& freq) {
        for (int d = 1; d <= 9; d++) {
            if (freq[d] != 0 && freq[d] != d)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int no = n + 1; ; no++) {
            int temp = no;
            array<int,10> freq = {0};
            while (temp > 0) {
                freq[temp % 10]++;
                temp /= 10;
            }
            if (check(freq)) return no;
        }
    }
};
