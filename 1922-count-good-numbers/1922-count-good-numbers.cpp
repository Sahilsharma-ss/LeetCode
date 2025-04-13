class Solution {
public:
  int MOD = 1e9 + 7;
    long long power(long long b,long long exp)
    {
        if(exp==0) return 1;
        long long result=0;
        long long half=power(b,exp/2);
        result=(half*half)%MOD;
        if(exp%2==1)
        {
            result=(b*result)%MOD;
        }
        return result%MOD;
    }
    int countGoodNumbers(long long n) {
        int odd=n/2;
        int even=(n+1)/2;
        long long Result =(power(5, even)%MOD * (power(4, odd)%MOD)) % MOD;
        return Result;
    }
};