class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans = 0;
        int sum = accumulate(cost.begin(),cost.end(),0);
        if(cost.size()<=2)
        {
            return sum;
        }
        for(int i=2;i<cost.size();i+=3)
        {
            ans+=cost[i];
        }
        return sum-ans;
    }
};