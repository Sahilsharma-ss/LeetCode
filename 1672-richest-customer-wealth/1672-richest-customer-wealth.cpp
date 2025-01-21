class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich =0;
        int sum=0;
        for(auto vec : accounts)
        {
            sum=0;
            for(int i=0 ;i<vec.size();i++)
            {
                sum=sum+vec[i];
            }
            rich =max(rich,sum);
        }
        return rich;
    }
};