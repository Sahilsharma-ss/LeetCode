class Solution {
public:
    vector<int>generaterow(int r)
    {
        vector<int>temp;
        long long int ans=1;
        temp.push_back(ans);
        for(int i=1;i<r;i++)
        {
            ans *=(r-i);  // row -columns
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};