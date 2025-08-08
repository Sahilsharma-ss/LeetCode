class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long no=n;
        if(no<0) no=-1*no;
        while(no>0)
        {
            if(no%2==1)
            {
                ans=ans*x;
                no--;
            }
            else
            {
                x=x*x;
                no/=2;
            }
        }
        if(n<0) ans=(double)1.0/(double) ans;
        return ans;
    }
};