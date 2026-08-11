class Solution {
public:
    bool check(int mid,vector<int>&wt,int d)
    {
        int cnt = 1;
        int ind =0;
        int curr = 0;
        while(ind<wt.size())
        {
            if(curr + wt[ind] <= mid)
            {
                curr += wt[ind];
                ind++;
            }
            else
            {
                cnt++;
                curr = 0;
            }
        }
        return cnt <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = std::accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(check(mid,weights,days))
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