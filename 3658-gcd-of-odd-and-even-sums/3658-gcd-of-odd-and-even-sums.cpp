class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = pow(n,2);
        int even = n*(n+1);
        return std :: gcd(odd,even);
    }
};