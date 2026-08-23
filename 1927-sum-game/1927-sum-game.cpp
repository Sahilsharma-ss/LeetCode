class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, sum2 = 0;
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                c1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                c2++;
            else
                sum2 += num[i] - '0';
        }

        int diff = sum1 - sum2;
        int qdiff = c1 - c2;

        if (qdiff % 2 != 0)
            return true;

        return diff != (c2 - c1) / 2 * 9;
    }
};