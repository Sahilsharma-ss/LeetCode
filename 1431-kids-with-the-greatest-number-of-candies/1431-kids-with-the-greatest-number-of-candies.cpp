class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max =0;
        vector<bool>res;
        int n = candies.size();
        for(auto i : candies)
        {
            if(i>max)
            {
                max=i;
            }
        }
            for(auto i : candies)
            {
                if((i+extraCandies)>=max)
                {
                    res.push_back(true);
                }
                else
                {
                    res.push_back(false);
                }
            }
        return res;
    }
};