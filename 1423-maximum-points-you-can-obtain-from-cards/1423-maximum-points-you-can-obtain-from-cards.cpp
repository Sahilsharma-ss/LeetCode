class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int l =0;
        int r = 0;
        int sz = n-k; // 7-3 = 4
        int mini = 1e9;
        int s = 0;
        while(r<n)
        {
            s += cardPoints[r];
            if(r>=sz)
            {
                s -= cardPoints[l];
                l++;
            }
            if(r-l+1==sz)
            {
                // cout<<s<<" ";
                mini = min(mini,s);
            }
            r++;
        }
        // cout<<"mini is "<<mini;
        return sum-mini;
    }
};