class Solution {
void solve(vector<int>&vec,int n)
{
    for(int i=2;i<n;i++)
    {
        vec[i]=1;
    }
    for(int i=2;i*i<n;i++)
    {
        if(vec[i]==1)
        {
            for(int j=i*i;j<n;j+=i)
            {
                vec[j]=0;
            }
        }
    }
}
public:
    int countPrimes(int n) {
        vector<int>vec(n);
        solve(vec,n);
    int cnt=0;
    for(int i=2;i<n;i++)
    {
        if(vec[i]==1)
        {
            cnt++;
        }
    }
    return cnt;
    }
};