class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0;
        for(auto i : gas)
        {
            sumg += i;
        }
        int sumc=0;
        for(auto i : cost)
        {
            sumc+=i;
        }
        if(sumg<sumc) return -1;
        int total =0;
        int result = 0;
        for(int i =0;i<gas.size();i++)
        {
            total += (gas[i]-cost[i]);
            if(total<0) 
            {
                total =0;
                result= i+1;
            }
        }
        return result;
    }
};