typedef long long ll;
class Solution {
public:
    long long countCommas(long long n) {
        ll cnt1 = n-999>0?n-999:0;
        ll cnt2 = n-999999>0?n-999999:0;
        ll cnt3 = n-999999999>0?n-999999999:0;
        ll cnt4 = n-999999999999>0?n-999999999999:0;
        ll cnt5 = n > 999999999999999 ? n - 999999999999999 : 0;
        return cnt1+cnt2+cnt3+cnt4+cnt5;
    }
};