class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int cnt = 0;
        int minus = 0;
        long long res = 0;
        for(auto i : happiness)
        {
            cnt++;
            res +=(i-minus)>0?(i-minus):0;
            minus++;
            if(cnt==k) break;
        }
        return res;
    }
};