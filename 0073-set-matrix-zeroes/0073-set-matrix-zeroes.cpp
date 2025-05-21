class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
     vector<pair<int,int>>vec;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    vec.push_back({i,j});
                }
            }
        }
        for(auto i : vec)
        {
            int r=i.first;
            int c=i.second;
            for(int i=0;i<n;i++)
            {
                matrix[r][i]=0;
            }
            for(int i=0;i<m;i++)
            {
                matrix[i][c]=0;
            }
        }
}
};
