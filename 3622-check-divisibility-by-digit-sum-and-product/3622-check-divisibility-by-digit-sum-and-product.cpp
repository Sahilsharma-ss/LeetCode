class Solution {
public:
    bool checkDivisibility(int n) {
        int prod =1;
        int sum = 0;
        int temp = n;
        while(n>0)
        {
            int r=n%10;
            sum+=r;
            prod*=r;
            n/=10;
        }
        return temp%(sum+prod)==0;
    }
};