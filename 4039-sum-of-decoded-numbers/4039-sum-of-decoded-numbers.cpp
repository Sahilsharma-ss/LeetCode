class Solution {
public:
    int mod = 1e9+7;
    long long power(long long a,long long b)
    {
        a = a%mod;
        long long val = 1;
        while(b>0)
        {
            if(b%2==1)
            {
                val = (val*a)%mod;
            }
            a = (1ll*a*a)%mod;
            b/=2;
        }
        return val;
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
      //  cout<<power(2,4)<<" ";
        for(long long i : nums)
        {
            int width = i%10;
            long long d = floor(i/10);
            string str = to_string(d);
            int a = stoi(str.substr(0,width));
            int b = stoi(str.substr(width));
           //cout<<a<<" "<<b<<endl;
            long long val = power(a,b);
            sum  = (sum+val)%mod;
        }
        return sum;
    }
};