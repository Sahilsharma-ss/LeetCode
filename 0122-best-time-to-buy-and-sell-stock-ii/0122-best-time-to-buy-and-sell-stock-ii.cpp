class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxp=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)
            {
                mini=prices[i];
            }
            else
            {
                maxp+=prices[i]-mini;
                mini=prices[i];
            }
        }
        return maxp;
    }
};