class Solution {
public:
    int addDigits(int num) {
        int k=0;
        int b=0;
        while(num!=0){
            int r=num%10;
            k = k + r; 
            num=num/10;
        }
        if(k>9)
        {
            while(k!=0)
            {
                int p=k%10;
                b=b+p;
                k=k/10;
            }
            return b;
        }
        else
        {
            return k;
        }
    }
};