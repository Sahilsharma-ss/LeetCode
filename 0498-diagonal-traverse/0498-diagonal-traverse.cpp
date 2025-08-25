class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int r=mat.size();
        int c=mat[0].size();
        int n=0;
        for(int i=0;i<r;i++)
        {
            vector<int>temp;
            int s=i,t=0;
            while(s>=0&&t>=0&&t<c)
            {
                temp.push_back(mat[s][t]);
                s--;
                t++;
            }
            if(i%2)
            {
                reverse(temp.begin(),temp.end());
            }
            for(auto i : temp)
            {
                ans.push_back(i);
            }
            n++;
        }
        for(int i=1;i<c;i++)
        {
            vector<int>tempp;
            int s=r-1;
            int t=i;
            while(s>=0 &&t >=0 && t<c)
            {
                tempp.push_back(mat[s][t]);
                s--;
                t++;
            }
            if(n++%2)
            {
                reverse(tempp.begin(),tempp.end());
            }
            for(auto i : tempp)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};