class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        int ans  = 0;
        int multiple = 1;
        for(int i=n;i>0;i--)
        {
            int no = i;
            string str = bitset<32>(no).to_string();
            str = str.substr(str.find('1'));
            int sum  =  0 ;
            for(int j = str.size()-1;j>=0;j--)
            {
                if(str[j]=='1')
                {
                    sum = (sum+multiple)%mod;
                }
                multiple = (multiple*2)%mod;
            }
            ans = (ans+sum)%mod;
        }
        return ans;
    }
};