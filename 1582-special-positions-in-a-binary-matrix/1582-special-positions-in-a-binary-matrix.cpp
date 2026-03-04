class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    int cnt = 0;
                    int cnt1=0;
                    int r=0;
                    int c=j;

                   while(r<n)
                   {
                    if(mat[r][j]==1)
                    {
                        cnt++;
                    }
                    r++;
                   }
                   int r1 = i;
                   int c1= 0;
                   while(c1<m)
                   {
                    if(mat[r1][c1]==1)
                    {
                        cnt1++;
                    }
                    c1++;
                   }
                   if(cnt==1&& cnt1==1) ans++;
                }

            }
        }
        return ans;
    }
};