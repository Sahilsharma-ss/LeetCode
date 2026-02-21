class Solution {
public:
    int setcount(int no)
    {
        int cnt = 0;
        while(no)
        {
            if(no&1) cnt++;
            no = no>>1;
        }
        return cnt;
    }
    bool isprime(int no)
    {
        if(no==1) return false;
        for(int i =2;i*i<=no;i++)
        {
            if(no%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++)
        {
            int count = setcount(i);
            if(isprime(count))
            {
                ans++;
            }
        }
        return ans;
    }
};