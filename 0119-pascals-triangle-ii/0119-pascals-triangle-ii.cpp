class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,1);
        long long ans=1;
        for(int i=1;i<=rowIndex;i++)
        {
            ans=(ans*(rowIndex-i+1))/i;
            res[i]=(int)ans;
        }
        return res;
    }
};