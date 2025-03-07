class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex +=1;
        vector<int>res;
        long long int ans=1;
        res.push_back(ans);
        for(int i=1;i<rowIndex;i++)
        {
            ans *=(rowIndex-i);
            ans=ans/i;
            res.push_back(ans);
        }
        return res;
    }
};