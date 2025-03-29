class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>res;
        int first=intervals[0][0];
        int last=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=last)
            {
                last = max(last,intervals[i][1]);
            }
            else
            {
                res.push_back({first,last});
                first=intervals[i][0];
                last=intervals[i][1];
            }
        }
        res.push_back({first,last});
        return res;
    }
};