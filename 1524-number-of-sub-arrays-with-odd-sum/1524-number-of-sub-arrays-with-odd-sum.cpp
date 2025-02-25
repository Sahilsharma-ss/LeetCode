class Solution {
public:
     int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>psum(n,0);
        psum[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            psum[i]=psum[i-1]+arr[i];
        }
        int count=0;
        int oddc=0;
        int evenc=1;
        for(int i=0;i<n;i++)
        {
            if(psum[i]%2==0)
            {
                count = (count+oddc)%M;
                evenc++;
            }
            else
            {
                count =(count+evenc)%M;
                oddc++;
            }
        }
        return count;
    }
};