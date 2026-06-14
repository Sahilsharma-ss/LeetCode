class Solution {
public:
    bool checkGoodInteger(int n) {
        int temp = n;
        int sum = 0;
        while(n>0)
        {
            sum += n%10;
            n/=10;
        }
        int power = 0;
        while(temp>0)
        {
            power+=pow(temp%10,2);
            if((power-sum)>=50) return true;
            temp/=10;
        }
        return false;
    }
};