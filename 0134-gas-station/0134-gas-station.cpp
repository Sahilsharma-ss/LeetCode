class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       // unique sol or no solution  it means there will be only one valid index
       // from where i can complete the journey circularly 

       int n = cost.size();
       int tot_cost = 0;  // if tot_cost < 0 it means no ans ret -1

       int extra_cost = 0;
       int startInd =0;
       for(int i=0;i<n;i++)
       {
            tot_cost += gas[i] - cost[i];
            extra_cost += gas[i] - cost[i];
            if(extra_cost<0)
            {
                extra_cost = 0;
                startInd = i+1;
            }
       }
       return tot_cost<0?-1:startInd;
    }
};