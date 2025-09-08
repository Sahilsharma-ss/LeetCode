class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int sum=0;
        int res=n/2;
        int temp=n;
        int c=0;
        int zerocnt=0;
        while(n!=0)
        {
            if(n%10==0)
            {
                zerocnt++;
            }
            c++;
            n/=10;
        }
        int div=10*c;
        int first=temp%div;
        vector<int>vec(2);
        if(zerocnt==0)
        {
            if(temp%2==0)
            {
                vec[0]=temp/2;
                vec[1]=temp/2;
            }
            else if(temp%2==1)
            {
                vec[0]=res;
                vec[1]=(res+1);
            }

        }
        else{
                vec[0]=first+1;
                vec[1]=temp-(first+1);
        }
        return vec;
    }
};