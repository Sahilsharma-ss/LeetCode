class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        int q = (str[0] - '0') * 10 + (str[2] - '0');
        int r = (str[1] - '0') * 10 + (str[3] - '0');

        return q + r;
    }
};
