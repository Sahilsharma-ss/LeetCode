class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int maxprofit=0;
        for(int price : prices)
        {
            if(price<minp)
            {
                minp=price;
            }
            else
            {
                maxprofit= max(maxprofit,price - minp);
            }
        }
        return maxprofit;
    }
};