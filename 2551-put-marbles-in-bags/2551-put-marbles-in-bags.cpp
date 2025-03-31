class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
    int n=weights.size();
    int m=n-1;
     vector<int>psum(m,0);
    for(int i=0;i<m;i++)
    {
        psum[i] = weights[i]+weights[i+1];
    }
    sort(psum.begin(),psum.end());
     long  max=0;
     long min=0;
    for(int i=0;i<k-1;i++)
    {
        min=min+psum[i];
        max=max+psum[m-i-1];
    }
    return max-min;   
    }
};