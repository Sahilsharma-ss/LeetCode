class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int i = 0;
        int ans = 0;
        while(  i < n &&coins>=costs[i])
        {
            ans++;
            coins-=costs[i];
            i++;
        }
        return ans;
    }
};