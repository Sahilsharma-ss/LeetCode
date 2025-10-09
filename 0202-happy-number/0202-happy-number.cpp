class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1 && !seen.count(n))
        {
            seen.insert(n);
            int sum=0;
            int temp=n;
            while(temp>0)
            {
                int r=temp%10;
                sum+=(r*r);
                temp/=10;
            }
            n=sum;
        }
        return n==1;
    }
};