class Solution {
public:
    bool check(int mid,vector<int>& bloomDay,int k,int m)
    {
        int ind = 0;
        int cnt =0;
        int curr =0;
        while(ind<bloomDay.size())
        {
           if(bloomDay[ind]<=mid)
           {
                curr++;
           }
           else
           {
                curr =0;
           }
           if(curr==k)
           {
                cnt++;
                curr = 0;
           }
           ind++;
        }
        return m<=cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<(1ll*m*k)) return -1;
        int l=1;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans =0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(check(mid,bloomDay,k,m))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};