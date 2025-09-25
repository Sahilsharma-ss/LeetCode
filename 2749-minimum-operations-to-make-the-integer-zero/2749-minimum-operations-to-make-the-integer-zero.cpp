class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;
        while(true)
        {
            long long val=1ll*num1-1ll*t*num2;
            if(val<0) return -1;
            if(__builtin_popcountll(val)<=t && t<=val)
            {
                break;
            }
            t++;
        }
        return t;
    }
};