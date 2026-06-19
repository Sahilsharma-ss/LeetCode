class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>psum(n+1);
        psum[0] = 0;
        for(int i=1;i<=n;i++)
        {
            psum[i] = psum[i-1]+gain[i-1];
        }
        int maxi = *max_element(psum.begin(),psum.end());
        return maxi;
    }
};