class Solution {
public:
string getCount(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end()); // Sort digits for easy comparison
    return s;
}

bool reorderedPowerOf2(int n) {
    string target = getCount(n); // Digit pattern of n
    for (int i = 0; i < 31; i++) { // 2^0 to 2^30 fits in int
        int power = 1 << i; // 2^i
        if (getCount(power) == target) {
            return true;
        }
    }
    return false;
}
};