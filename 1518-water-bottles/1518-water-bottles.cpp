class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot=numBottles;
        while((numBottles/numExchange) >=1)
        {
            int a=numBottles/numExchange;
            tot+=a;
            numBottles=(a+numBottles%numExchange);
        }
        return tot;
    }
};