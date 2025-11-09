class Solution {
public:
    int countOperations(int num1, int num2) {
         if(num1==0 || num2 ==0) return 0;
        if(num1==num2) return 1;
        int cnt=0;
        while(num1>0 || num2>0)
        {
            if(num1>num2)
            {
                num1=num1-num2;
                cnt++;
            }
            if(num2>num1)
            {
                num2=num2-num1;
                cnt++;
            }
            if(num1==num2) return cnt+1;
        }
        return cnt;
    }
};