class Solution {
public:
    bool check(int mid,vector<int>&piles,int h)
    {
        long long tot = 0;
        for(int i : piles)
        {
            if(i%mid==0)
            {
                tot += i/mid;
            }
            else
            {
                tot += i/mid + 1;
            }
        }
        return tot<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int r =*max_element(piles.begin(),piles.end());
        int ans = 0;
        while(l<=r) // nlogn
        {
            int mid = l+(r-l)/2;
            if(check(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};