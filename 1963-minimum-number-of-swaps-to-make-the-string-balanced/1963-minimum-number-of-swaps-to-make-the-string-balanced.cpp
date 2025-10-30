class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, open = 0;
        for (char c : s) {
            if (c == '[') open++;
            else {
                if (open > 0) open--;
                else imbalance++; 
            }
        }
        return (imbalance + 1) / 2;
    }
};
